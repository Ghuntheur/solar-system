#pragma once

#include <glimac/Image.hpp>
#include <GL/glew.h>

class Texture {

private:
  glimac::FilePath m_url;
  std::unique_ptr<glimac::Image> m_image;
  GLuint m_texture;

public:
  Texture(glimac::FilePath url);
  void init();
  void generate();
  void bind();
  void unbind();
  void addTarget();
  void locate(GLint, int = 0);
  void remove();
};
