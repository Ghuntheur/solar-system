#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <glimac/glm.hpp>

#include "Render/Texture.hpp"
#include "Render/Sphere.hpp"

class Scene;
class CustomProgram;
class Texture;

class Object {

protected:
  Scene *m_scene;
  CustomProgram *m_program;
  Texture *m_texture;
  Sphere *m_sphere;

  glm::vec3 m_pos;
  float m_timeRatio = 10.f;

  // LOCATION MATRIX SHADERS
  GLint u_projMatrix;
  GLint u_modelMatrix;
  GLint u_viewMatrix;
  GLint u_normalMatrix;
  GLint u_texture;

  // MATRIX
  glm::mat4 m_modelMatrix;
  glm::mat4 m_normalMatrix;
  glm::mat4 m_baseMatrix;


public:
  Object() = default;
  Object(CustomProgram *);

  virtual void init();
  virtual void attach(Scene *);
  virtual void render();
  virtual void animate() = 0;

  inline const float getTimeRatio() const { return this->m_timeRatio; }

};


