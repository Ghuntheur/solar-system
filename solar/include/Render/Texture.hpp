#pragma once

#include <glimac/Image.hpp>
#include <GL/glew.h>

class Texture {

private:
  std::string m_url;
  std::unique_ptr<glimac::Image> m_image;
  GLuint m_texture;

public:
  Texture(std::string url);
  void init();
  void generate();
  void bind();
  void unbind();

};
