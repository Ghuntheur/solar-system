#pragma once
#define GLEW_STATIC

#include <assert.h>
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

  // LOCATION MATRIX SHADERS
  GLint u_MVPMatrix;
  GLint u_MVMatrix;
  GLint u_NormalMatrix;
  GLint u_Texture;

  // MATRIX
  glm::mat4 m_MVMatrix;
  glm::mat4 m_NormalMatrix;

public:
  Object() = default;
  Object(glm::vec3, CustomProgram *);

  virtual void init();
  virtual void attach(Scene *);
  virtual void render();

};


