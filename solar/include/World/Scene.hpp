#pragma once

#define GLEW_STATIC

#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <list>

#include "Vendors/CustomProgram.hpp"
#include "Objects/Object.hpp"
#include "Objects/Planet.hpp"
#include "App.hpp"

class Object;

class Scene {

private:
  bool m_ready = false;
  GLfloat m_aspectRatio;
  CustomProgram m_program;

  glm::mat4 m_projMatrix;
  std::list<Object *> m_planets;


public:
  void init();
  void loadPlanets();
  void render();
  void keyPressed(uint32_t, bool);
  void mouseMove(glm::ivec2 &);
  void mousePressed(uint32_t, bool);

  inline const glm::mat4& getProjMatrix() const { return this->m_projMatrix; }

private:
  void reshape(int, int, GLfloat = 45.0f);
  template <class T> void addToList(std::list<T *> &list, T *object);
  template <class T> void renderList(std::list<T *> &list);
};

