#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <glimac/common.hpp>
#include <GL/gl.h>

class VBO {

public:
  VBO();

  void bind();
  void unbind();
  void addVertices(int vertexCount, const void *data);
  void remove();

private:
  GLuint vbo;

};


