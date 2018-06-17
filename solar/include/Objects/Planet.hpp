#pragma once

#define _USE_MATH_DEFINES
#include "Objects/Object.hpp"
#include "World/Scene.hpp"
#include "Objects/Satellite.hpp"
#include <cmath>


class Planet : public Object {

private:
  std::string m_name;
  float m_aphelion;
  float m_perihelion;
  int m_diameter;
  float m_orbitalPeriod;
  float m_dayLength;
  float m_inclination;
  bool m_hasSatellites;

public:
  Planet(std::string name, float aphelion, float perihelion, int diameter,
         float orbitalPeriod, float dayLength, float inclination, bool hasSatellites,
         CustomProgram *program);

  inline const std::string getName() const { return this->m_name; }
  inline const float getOrbitalPeriod() const { return this->m_orbitalPeriod; }

  void render() override;
  void animate() override;
  void move() override;
  void drawOrbits();

};

