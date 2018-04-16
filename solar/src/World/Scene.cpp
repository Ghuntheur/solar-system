#include "World/Scene.hpp"

void Scene::init() {
  this->reshape(App::instance()->getWidth(), App::instance()->getHeight());
  // CAMERAS
}

void Scene::loadPlanets() {
  std::ifstream file(App::s_appPath + "assets/planets.csv");
  if (!file.is_open()) throw std::runtime_error("planets file does not exists");

  Object *object;

  std::string planetName, aphelion, perihelion, diameter, orbitalPeriod, dayLength, inclination;

  std::string line;
  while (!file.eof()) {
    std::getline(file, line, ',');
    planetName = line;
    std::getline(file, line, ',');
    aphelion = line;
    std::getline(file, line, ',');
    perihelion = line;
    std::getline(file, line, ',');
    diameter = line;
    std::getline(file, line, ',');
    orbitalPeriod = line;
    std::getline(file, line, ',');
    dayLength = line;
    std::getline(file, line, '\n');
    inclination = line;

    // object = new Planet()

  }

  file.close();
}

void Scene::reshape(const int width, int height, const GLfloat fov) {
  this->m_aspectRatio = (GLfloat) width / height;
  this->m_projMatrix = glm::perspective(glm::radians(fov), this->m_aspectRatio, 0.1f, 100.f);
}