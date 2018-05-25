#pragma once

#include "Objects/Object.hpp"
#include "World/Scene.hpp"

class Planet : public Object {

private:
  std::string m_name;
  float m_aphelion;
  float m_perihelion;
  int m_diameter;
  float m_orbitalPeriod;
  float m_dayLength;
  float m_inclination;

public:
  Planet(std::string name, float aphelion, float perihelion, int diameter,
         float orbitalPeriod, float dayLength, float inclination,
         CustomProgram *program);

  void animate() override;
  void move() override;

};

