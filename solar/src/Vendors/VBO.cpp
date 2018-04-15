#include "Vendors/VBO.hpp"

VBO::VBO() {
  glGenBuffers(1, &this->vbo);
}

/* --------------------------------- */

void VBO::bind() {
  glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
}

void VBO::unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::addVertices(int vertexCount, const void *data) {
  glBufferData(GL_ARRAY_BUFFER, vertexCount*sizeof(glimac::ShapeVertex), data, GL_STATIC_DRAW);
}

void VBO::remove() {
  glDeleteBuffers(1, &this->vbo);
}