#pragma once

#define GLEW_STATIC

#include <glimac/Program.hpp>

struct CustomProgram {

  glimac::Program m_program;

  CustomProgram() {
    this->m_program = glimac::loadProgram(
      "./shaders/3D.vs.glsl",
      "./shaders/texture.fs.glsl"
    );
  }

  const GLuint getGLId() {
    return this->m_program.getGLId();
  }

  void use() {
    this->m_program.use();
  }

};


