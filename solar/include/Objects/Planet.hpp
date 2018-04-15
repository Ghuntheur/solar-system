#pragma once

#include <iostream>
#include <string>

#include "World/Scene.hpp"

class Scene;

class Planet {

private:
  std::string m_name;
  float m_aphelion;
  float m_perihelion;
  int m_diameter;
  float m_orbitalPeriod;
  float m_dayLength;
  float m_inclination;


public:
  Planet(std::string name, float aphelion, float perihelion, int diameter, float orbitalPeriod, float dayLength, float inclination);
  void init();
  void attach(Scene *scene);

};

