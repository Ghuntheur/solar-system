#include "World/Scene.hpp"

void Scene::init() {
  this->initCameras();

  this->reshape(App::instance()->getWidth(), App::instance()->getHeight(), this->m_cameras[this->m_currentCamera]->getFov());
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
  while (file.good()) {
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

    object = new Planet(planetName, aphelion, perihelion, diameter, orbitalPeriod,
                        dayLength, inclination, &this->m_program);
    addToList<Object>(this->m_planets, object);
  }

  file.close();
}

void Scene::render() {
  this->renderList(this->m_planets);
}

void Scene::keyPressed(const uint32_t key, const bool active) {
  if (active) {
    if (key == SDLK_c) {

    }
  }
}

void Scene::mouseMove(const glm::ivec2 &pos) {
  if (this->m_currentCamera == TOP_VIEW) {
    this->m_cameras[TOP_VIEW]->rotateLeft(pos.x * 0.5f);
  }
}

void Scene::mousePressed(const uint32_t type, const bool active) {
  if (type == SDL_BUTTON_WHEELDOWN) {
    this->m_cameras[TOP_VIEW]->moveFront(-1.f);
    this->changeFov(this->m_cameras[this->m_currentCamera], 1.f);
  }
  if (type == SDL_BUTTON_WHEELUP) {
    this->m_cameras[TOP_VIEW]->moveFront(1.f);
    this->changeFov(this->m_cameras[this->m_currentCamera], -1.f);
  }
}

const glm::mat4 Scene::getViewMatrix() {
  return this->m_cameras[this->m_currentCamera]->getViewMatrix();
}

const unsigned int Scene::getCameraUID() {
  return this->m_cameras[this->m_currentCamera]->getUID();
}

/* ----------------------------- */

void Scene::reshape(const int width, int height, const GLfloat fov) {
  if (width != -1 && height != -1) this->m_aspectRatio = (GLfloat) width / height;
  this->m_projMatrix = glm::perspective(glm::radians(fov), this->m_aspectRatio, 0.1f, 100.f);
  this->m_globalMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -5))*this->m_cameras[this->m_currentCamera]->getViewMatrix();
}

void Scene::initCameras() {
  this->m_cameras[TOP_VIEW] = new TrackballCamera();
  this->m_cameras[PROFILE_VIEW] = new TrackballCamera();

  this->m_cameras[TOP_VIEW]->setPosition(0, -40.f, 0);
  this->m_cameras[TOP_VIEW]->setFov(100.f);
  this->m_cameras[TOP_VIEW]->rotateUp(90.f);
}

void Scene::changeFov(Camera *cam, float value) {
  float camFov = cam->getFov();
  float fov = camFov + value;

  if (fov != camFov) {
    cam->setFov(fov);
    this->reshape(-1, -1, fov);
  }
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