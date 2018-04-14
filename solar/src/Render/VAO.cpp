#define GLEW_STATIC
#include <glimac/common.hpp>
#include "Render/VAO.hpp"

VAO::VAO() {
  glGenVertexArrays(1, &this->m_vao);
  this->m_typeLenght = 0;
}

/* ---------------------------------------- */

void VAO::setOffset(GLint count, ...) {
  va_list args;
  va_start(args, count);

  this->m_componentSize.emplace_back(0);
  for (int i=0; i<count; i++) {
    GLint nb = va_arg(args, GLint);
    this->m_componentSize.emplace_back(nb);
    this->m_typeLenght += nb;
  }
}

/* ---------------------------------------- */

void VAO::bind() {
  glBindVertexArray(this->m_vao);
}

void VAO::unbind() {
  glBindVertexArray(0);
}

void VAO::remove() {
  glDeleteVertexArrays(1, &this->m_vao);
}

void VAO::enableVertex(const GLuint count, ...) {
  va_list args;
  va_start(args, count);

  for (int i=0; i<count; i++) {
    GLuint nb = va_arg(args, GLuint);
    glEnableVertexAttribArray(nb);
    this->m_vertexAttribute.emplace_back(nb);
  }
  va_end(args);
}

void VAO::attribVertex(GLenum type) {
  int size = this->m_vertexAttribute.size();
  for (int i=0; i<size; i++) {
    glVertexAttribPointer(
      this->m_vertexAttribute[i],
      this->m_componentSize[i+1],
      type,
      GL_FALSE,
      this->m_typeLenght*sizeof(type),
      (const GLvoid*)(this->m_componentSize[i]*sizeof(type)*this->m_vertexAttribute[i])
    );
  }
}
