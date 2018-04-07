#pragma once

#include <glimac/SDLWindowManager.hpp>

class Application {

private:
  int m_width;
  int m_height;
  std::string m_title;

  glimac::SDLWindowManager *m_window;
  static Application *m_instance;
  Application();


public:
  ~Application();

  static int initSDL();
  void init(const std::string title, const int widthh, const int height);

  // GETTER
  inline const std::string getTitle() const { return this->m_title; }
  inline const int getWindowWidth() const { return this->m_width; }
  inline const int getWindowHeight() const { return this->m_height; }

  // SETTER
  inline void setTitle(const std::string title) { this->m_title = title; }
  inline void setWidth(const int width) { this->m_width = width; }
  inline void setheight(const int height) { this->m_height = height; }

};
