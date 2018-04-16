#pragma once
#define GLEW_STATIC

#include <assert.h>
#include <GL/glew.h>

#include "World/Scene.hpp"

class Scene;
class CustomProgram;

class Object {

protected:
  Scene *m_scene;
  CustomProgram *m_program;

  // MATRIX
  GLint u_MVPMatrix;
  GLint u_MVMatrix;
  GLint u_NormalMatrix;
  GLint u_Texture;

public:
  Object() = default;
  Object(CustomProgram *);

  virtual void init();
  virtual void attach(Scene *);
  virtual void render();

};


