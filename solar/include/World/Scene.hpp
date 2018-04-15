#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <list>

#include "Objects/Planet.hpp"
#include "App.hpp"

class Planet;

class Scene {

private:
  bool m_ready = false;
  GLfloat m_aspectRatio;

  glm::mat4 m_projMatrix;
  std::list<Planet *> m_planets;

public:
  void init();
  void render();
  void keyPressed(uint32_t, bool);
  void mouseMove(glm::ivec2 &);
  void mousePressed(uint32_t, bool);
  void loadPlanets();

private:
  void reshape(int, int, GLfloat = 45.0f);

};

