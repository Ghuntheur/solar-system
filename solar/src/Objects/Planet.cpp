#include "Objects/Planet.hpp"


Planet::Planet(std::string name, float aphelion, float perihelion, int diameter,
               float orbitalPeriod, float dayLength, float inclination, glm::vec3 pos, CustomProgram *program)
  : Object(pos, program), m_name(name), m_aphelion(aphelion), m_perihelion(perihelion), m_diameter(diameter),
    m_orbitalPeriod(orbitalPeriod), m_dayLength(dayLength), m_inclination(inclination) {

  glimac::FilePath image  = this->m_name + ".jpg";
  this->m_texture = new Texture(App::s_appPath + "assets/textures/planets/" + image);

}