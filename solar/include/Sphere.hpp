#pragma once

#include <glimac/Sphere.hpp>
#include <VBO.hpp>
#include <VAO.hpp>

class Sphere : public glimac::Sphere {

private:
  VAO m_vao;
  VBO m_vbo;

public:
  Sphere(GLfloat radius, GLsizei discLat, GLsizei discLong);

  void initBuffers();
  void draw();

};
