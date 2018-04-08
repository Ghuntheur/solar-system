#include <Objects/Sphere.hpp>

Sphere::Sphere(GLfloat radius, GLsizei discLat, GLsizei discLong)
  : glimac::Sphere(radius, discLat, discLong) { }

void Sphere::initBuffers() {
  this->m_vbo.bind();
  this->m_vbo.addVertices(this->getVertexCount(), this->getDataPointer());
  this->m_vbo.unbind();

  this->m_vao.bind();
  this->m_vao.enableVertex(3, 0, 1, 2);
  this->m_vao.setOffset(3, 3, 3, 2);

  this->m_vbo.bind();
  this->m_vao.attribVertex(GL_FLOAT);
  this->m_vbo.unbind();
  this->m_vao.unbind();
}

void Sphere::draw() {
  this->m_vao.bind();
  glDrawArrays(GL_TRIANGLES, 0, this->getVertexCount());
}