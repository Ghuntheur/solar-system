#include "Objects/Planet.hpp"

Planet::Planet(std::string name, float aphelion, float perihelion, int diameter,
               float orbitalPeriod, float dayLength, float inclination, CustomProgram *program)
  : Object(program), m_name(name), m_aphelion(aphelion), m_perihelion(perihelion), m_diameter(diameter),
    m_orbitalPeriod(orbitalPeriod), m_dayLength(dayLength), m_inclination(inclination) {}