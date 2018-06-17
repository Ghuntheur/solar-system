#pragma once

#include "Objects/Object.hpp"
#include "World/Scene.hpp"
#include "Objects/Planet.hpp"

class Planet;

class Satellite : public  Object {

private:
  Planet *m_planet;

  std::string m_name;
  int m_diameter;
  float m_distance;
  float m_inclination;

public:
  Satellite(std::string name, int diameter, float distance, float inclination, Planet *planet, CustomProgram *program);

  void render() override;
  void animate() override;
  void move() override;
};


