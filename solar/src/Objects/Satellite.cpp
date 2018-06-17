#include "Objects/Satellite.hpp"

Satellite::Satellite(std::string name, int diameter, float distance, float inclination, Planet *planet, CustomProgram *program)
  : Object(program), m_name(name), m_diameter(diameter), m_distance(distance), m_inclination(inclination) {

  float distRatio = 1/100000.f;

  this->m_texture = new Texture(App::s_appPath + "assets/textures/satellites/Lune.jpg");
  this->m_sphere = new Sphere((this->m_diameter/2) * distRatio, 32, 16);
  this->m_pos = glm::vec3(this->m_distance * 1000, 0, 0);

  this->m_planet = planet;

}

void Satellite::render() {
  this->move();
  this->animate();
  this->m_normalMatrix = glm::transpose(glm::inverse(this->m_modelMatrix));

  this->draw();
}


void Satellite::animate() {

}

void Satellite::move() {

}
