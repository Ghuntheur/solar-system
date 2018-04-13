#include <iostream>
#include "Render/Texture.hpp"

Texture::Texture(std::string url)
  : m_url(url) {

  this->init();

}

void Texture::init() {
  std::cout << this->m_url << std::endl;
}