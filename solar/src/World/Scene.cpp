#include "World/Scene.hpp"

void Scene::init() {
  this->reshape(App::instance()->getWidth(), App::instance()->getHeight());

  this->m_cameras[TOP_VIEW] = new TrackballCamera();
  this->m_cameras[PROFILE_VIEW] = new TrackballCamera();
}

void Scene::loadPlanets() {
  std::ifstream file(App::s_appPath + "assets/planets.csv");
  if (!file.is_open()) throw std::runtime_error("planets file does not exists");

  Object *object;

  std::string planetName;
  float aphelion, perihelion, orbitalPeriod, dayLength, inclination;
  int diameter;

  std::string line;
  std::getline(file, line);
  int i = 0;
  while (file.good()) {
    glm::vec3 pos(i, 0, 0);
    std::getline(file, line, ',');
    planetName = line;
    std::getline(file, line, ',');
    aphelion = std::stof(line);
    std::getline(file, line, ',');
    perihelion = std::stof(line);
    std::getline(file, line, ',');
    diameter = std::atoi(line.c_str());
    std::getline(file, line, ',');
    orbitalPeriod = std::stof(line);
    std::getline(file, line, ',');
    dayLength = std::stof(line);
    std::getline(file, line, '\n');
    inclination = std::stof(line);
    i++;

    object = new Planet(planetName, aphelion, perihelion, diameter, orbitalPeriod,
                        dayLength, inclination, pos, &this->m_program);
    addToList<Object>(this->m_planets, object);
  }

  file.close();

  this->initCameras();
}

void Scene::render() {
  this->renderList(this->m_planets);
}

const glm::mat4 Scene::getViewMatrix() {
  return this->m_cameras[this->m_currentCamera]->getViewMatrix();
}

const unsigned int Scene::getCameraUID() {
  return this->m_cameras[this->m_currentCamera]->getUID();
}

/* ----------------------------- */

void Scene::reshape(const int width, int height, const GLfloat fov) {
  this->m_aspectRatio = (GLfloat) width / height;
  this->m_projMatrix = glm::perspective(glm::radians(fov), this->m_aspectRatio, 0.1f, 100.f);
}

void Scene::initCameras() {

}

template <class T> void Scene::addToList(std::list<T *> &list, T *object) {
  object->init();
  object->attach(this);
  list.push_back(object);
}

template <class T> void Scene::renderList(std::list<T *> &list) {
  for (auto it = list.begin(); it != list.end(); ++it) {
    (*it)->render();
  }
}

template <class T> void Scene::deleteList(std::list<T *> &list) {
  for (auto it = list.begin(); it != list.end(); ++it) {
    delete *it;
  }
  list.clear();
}

Scene::~Scene() {
  this->deleteList(this->m_planets);

  for (const auto &temp : this->m_cameras) {
    delete temp.second;
  }
}