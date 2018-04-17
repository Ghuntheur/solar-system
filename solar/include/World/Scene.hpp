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
#include "Camera/ViewType.hpp"
#include "Camera/Camera.hpp"
#include "Camera/TrackballCamera.hpp"

class Object;

class Scene {

private:
  bool m_ready = false;
  GLfloat m_aspectRatio;
  CustomProgram m_program;
  std::unordered_map<ViewType, Camera *> m_cameras;
  ViewType m_currentCamera = TOP_VIEW;

  glm::mat4 m_projMatrix;

  std::list<Object *> m_planets;

public:
  void init();
  void loadPlanets();
  void render();
  void keyPressed(uint32_t, bool);
  void mouseMove(glm::ivec2 &);
  void mousePressed(uint32_t, bool);

  const glm::mat4 getViewMatrix();
  const unsigned int getCameraUID();

  inline const glm::mat4& getProjMatrix() const { return this->m_projMatrix; }
  inline const ViewType getViewType() const { return this->m_currentCamera; }
  inline const glm::vec3 getCameraPos() { return this->m_cameras[this->m_currentCamera]->getPosition(); }
  inline const isReady() const { return this->m_ready; }

  ~Scene();

private:
  void reshape(int, int, GLfloat = 45.0f);
  void initCameras();
  template <class T> void addToList(std::list<T *> &list, T *object);
  template <class T> void renderList(std::list<T *> &list);
  template <class T> void deleteList(std::list<T *> &list);
};

