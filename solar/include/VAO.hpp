#pragma once

#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <cstdarg>
#include <vector>
#include <typeinfo>

class VAO {

public:
  VAO();
  void bind();
  void unbind();
  void remove();

  void enableVertex(GLuint count, ...);
  void attribVertex(GLenum type);
  void setOffset(GLint count, ...);

private:
  GLuint m_vao;
  std::vector<GLuint> m_vertexAttribute;
  std::vector<GLint> m_componentSize;
  int m_typeLenght;

};


