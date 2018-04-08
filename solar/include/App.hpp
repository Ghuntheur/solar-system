#pragma once

#include <glimac/SDLWindowManager.hpp>

class App {

private:
  int m_width;
  int m_height;
  std::string m_title;

  bool m_running = false;

  glimac::SDLWindowManager *m_window;

  static App * s_instance;

  App();
  static int initSDL();

public:
  ~App();
  static App *instance();

  void init(std::string title, int widthh, int height);
  void start();
  void run();
  void stop();

  // GETTER
  inline const std::string getTitle() const { return this->m_title; }
  inline const int getWindowWidth() const { return this->m_width; }
  inline const int getWindowHeight() const { return this->m_height; }

  // SETTER
  inline void setTitle(const std::string title) { this->m_title = title; }
  inline void setWindowWidth(const int width) { this->m_width = width; }
  inline void setWindowHeight(const int height) { this->m_height = height; }

};
