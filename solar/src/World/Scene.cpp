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
  bool hasSatellites;

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
    std::getline(file, line, ',');
    inclination = std::stof(line);
    std::getline(file, line, '\n');
    hasSatellites = line == "true";

    object = new Planet(planetName, aphelion, perihelion, diameter, orbitalPeriod,
                        dayLength, inclination, hasSatellites, &this->m_program);
    if (hasSatellites) this->loadSatellites(object);
    this->addToList<Object>(this->m_planets, object);
  }

  file.close();
}

void Scene::loadSatellites(Object *object) {
  Planet *planet = dynamic_cast<Planet *>(object);

  glimac::FilePath path = planet->getName() + ".csv";
  std::ifstream file(App::s_appPath + "assets/satellites/" + path);
  if (!file.is_open()) throw std::runtime_error(path + " file does not exsist");

  Object *satellite;

  std::string name;
  int diameter;
  float distance, inclination;

  std::string line;
  std::getline(file, line);
  while (file.good()) {
    std::getline(file, line, ',');
    name = line;
    std::getline(file, line, ',');
    diameter = std::atoi(line.c_str());
    std::getline(file, line, ',');
    distance = std::stof(line);
    std::getline(file, line, '\n');
    inclination = std::stof(line);
  }

  satellite = new Satellite(name, diameter, distance, inclination, planet, &this->m_program);
  this->addToList<Object>(this->m_satellites, satellite);

  file.close();
}

void Scene::render() {
  this->renderList(this->m_planets);
  this->renderList(this->m_satellites);
}

void Scene::keyPressed(const uint32_t key, const bool active) {
  if (active) {
    if (key == SDLK_c) {
      size_t i = static_cast<size_t>(this->m_currentCamera);
      size_t n = this->m_cameras.size();

      i++;
      if (i >= n) i = 0;
      if (i < 0) i = n-1;

      this->m_currentCamera = static_cast<ViewType>(i);
      this->reshape(-1, -1, this->m_cameras[this->m_currentCamera]->getFov());
    }
    
    if (key == SDLK_s) {
      this->setSpeed(200.f);
    } 
  }

  if (!active) {
    if (key == SDLK_s) {
      this->setSpeed(-200.f);
    }
  }
}

void Scene::mouseMove(const glm::ivec2 &pos) {
  if (this->m_currentCamera == PROFILE_VIEW) {
    this->m_cameras[PROFILE_VIEW]->rotateLeft(pos.x * 0.5f);
  }
}

void Scene::mousePressed(const uint32_t type, const bool active) {
  if (type == SDL_BUTTON_WHEELDOWN) {
    this->m_cameras[this->m_currentCamera]->moveFront(1.f);
    this->changeFov(this->m_cameras[this->m_currentCamera], 1.f);
  }
  if (type == SDL_BUTTON_WHEELUP && this->m_cameras[this->m_currentCamera]->getDistance() > 2.f) {
    this->m_cameras[this->m_currentCamera]->moveFront(-1.f);
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
}

void Scene::initCameras() {
  this->m_cameras[TOP_VIEW] = new TrackballCamera();
  this->m_cameras[PROFILE_VIEW] = new TrackballCamera();
  // this->m_cameras[PLANET_VIEW] = new TrackballCamera();

  this->m_cameras[TOP_VIEW]->setPosition(0, 0, 0);
  this->m_cameras[TOP_VIEW]->setFov(100.f);
  this->m_cameras[TOP_VIEW]->rotateUp(90.f);
  this->m_cameras[TOP_VIEW]->rotateLeft(0.f);

  this->m_cameras[PROFILE_VIEW]->setPosition(0, 0, 0);
  this->m_cameras[PROFILE_VIEW]->setFov(80.f);
  this->m_cameras[PROFILE_VIEW]->rotateUp(0.f);
  
 /* this->m_cameras[PLANET_VIEW]->setPosition(this->m_planets[4]->getPosition());
  this->m_cameras[PLANET_VIEW]->setDistance(1.f);
  this->m_cameras[PLANET_VIEW]->setFov(100.f);
  this->m_cameras[PLANET_VIEW]->rotateUp(90.f);
  this->m_cameras[PLANET_VIEW]->rotateLeft(0.f); */
}

void Scene::changeFov(Camera *cam, float value) {
  float camFov = cam->getFov();
  float fov = camFov + value;

  if (fov != camFov) {
    cam->setFov(fov);
    this->reshape(-1, -1, fov);
  }
}

template <class T> void Scene::addToList(std::vector<T *> &list, T *object) {
  object->init();
  object->attach(this);
  list.push_back(object);
}

template <class T> void Scene::renderList(std::vector<T *> &list) {
  for (auto it = list.begin(); it != list.end(); ++it) {
    (*it)->render();
  }
}

template <class T> void Scene::deleteList(std::vector<T *> &list) {
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