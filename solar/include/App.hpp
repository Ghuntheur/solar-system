#define GLEW_STATIC
#pragma once

#include <glimac/SDLWindowManager.hpp>
#include <glimac/FilePath.hpp>

#include "Vendors/Utilities.hpp"

class App {

private:

  static App *s_instance;
  glimac::SDLWindowManager *m_window;

  int m_width = 800;
  int m_height = 800;
  std::string m_title = "Solar System";

  bool m_running = false;

  App();

public:
  static App *instance();

  void init();
  void start();
  void run();
  void stop();

};



