#include "Objects/Planet.hpp"


Planet::Planet(std::string name, float aphelion, float perihelion, int diameter,
               float orbitalPeriod, float dayLength, float inclination, CustomProgram *program)
  : Object(program), m_name(name), m_aphelion(aphelion), m_perihelion(perihelion), m_diameter(diameter),
    m_orbitalPeriod(orbitalPeriod), m_dayLength(dayLength), m_inclination(inclination) {

  float distRatio = 1/100000.f;

  glimac::FilePath image  = this->m_name + ".jpg";
  this->m_texture = new Texture(App::s_appPath + "assets/textures/planets/" + image);
  this->m_sphere = new Sphere((this->m_diameter/2) * distRatio, 32, 16);
  this->m_pos = glm::vec3(this->m_aphelion / 120, 0, 0);
}

void Planet::animate() {
  float time = App::instance()->getTime() * this->getTimeRatio() / this->m_dayLength;
  this->m_modelMatrix = glm::rotate(this->m_modelMatrix, time, glm::vec3(0, 1, 0));
}

void Planet::move() {
  float time = App::instance()->getTime() * this->getTimeRatio() / this->m_orbitalPeriod;
  this->m_modelMatrix = glm::rotate(this->m_baseMatrix, time, glm::vec3(0, 1, 0));
  this->m_modelMatrix = glm::translate(this->m_modelMatrix, this->m_pos);
}