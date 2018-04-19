#define GLEW_STATIC
#pragma once

#include <glimac/SDLWindowManager.hpp>
#include <glimac/FilePath.hpp>

#include "Vendors/Utilities.hpp"
#include "StateController.hpp"
#include "States/PlayState.hpp"

class App {

private:

  static App *s_instance;
  glimac::SDLWindowManager *m_window;
  StateController *m_stateController;

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
  float getTime();

  inline const int getWidth() const { return this->m_width; }
  inline const int getHeight() const { return this->m_height; }

  static glimac::FilePath s_appPath;
};



