#pragma once

#define GLEW_STATIC

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <GL/glew.h>
#include <glm/glm.hpp>

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

  std::vector<Object *> m_planets;
  std::vector<Object *> m_satellites;

  float m_speed = 50;
  float m_positionSpeed = 50;

public:
  void init();
  void loadPlanets();
  void loadSatellites(Object *object);
  void render();
  void keyPressed(uint32_t, bool);
  void mouseMove(const glm::ivec2 &);
  void mousePressed(uint32_t, bool);

  const glm::mat4 getViewMatrix();
  const unsigned int getCameraUID();

  inline const glm::mat4& getProjMatrix() const { return this->m_projMatrix; }
  inline const ViewType getViewType() const { return this->m_currentCamera; }
  inline const glm::vec3 getCameraPos() { return this->m_cameras[this->m_currentCamera]->getPosition(); }
  inline const bool isReady() const { return this->m_ready; }
  inline const float getSpeed() const { return this->m_speed; }
  inline const float getPositionSpeed() const { return this->m_positionSpeed; }

  inline const setSpeed(const float speed) { this->m_speed += speed; }
  inline const setPositionSpeed(const float speed) { this->m_positionSpeed = speed; }

  ~Scene();

private:
  void reshape(int, int, GLfloat);
  void initCameras();
  void changeFov(Camera *, float);
  template <class T> void addToList(std::vector<T *> &list, T *object);
  template <class T> void renderList(std::vector<T *> &list);
  template <class T> void deleteList(std::vector<T *> &list);
};

