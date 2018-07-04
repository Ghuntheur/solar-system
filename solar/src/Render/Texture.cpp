#define GLEW_STATIC
#include <iostream>
#include <glimac/FilePath.hpp>

#include "Render/Texture.hpp"

Texture::Texture(std::string url)
  : m_url(url) {
  this->init();
}

void Texture::init() {
  this->m_image = glimac::loadImage(this->m_url);
  glGenTextures(1, &this->m_texture);
  this->generate();
  this->bind();
  this->addTarget();
  this->unbind();
}

void Texture::generate() {
  glGenTextures(1, &this->m_texture);
}

void Texture::bind() {
  glBindTexture(GL_TEXTURE_2D, this->m_texture);
}

void Texture::unbind() {
  glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::addTarget() {
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(
    GL_TEXTURE_2D,
    0,
    GL_RGBA,
    this->m_image->getWidth(),
    this->m_image->getHeight(),
    0,
    GL_RGBA,
    GL_FLOAT,
    this->m_image->getPixels()
  );
}

void Texture::locate(GLint location, int value) {
  glUniform1i(location, value);
}

void Texture::remove() {
  glDeleteTextures(1, &this->m_texture);
}