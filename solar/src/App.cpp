#include "App.hpp"

App *App::s_instance = nullptr;

App::App() { }

App *App::instance() {
  if (!s_instance) {
    s_instance = new App;
  }
  return s_instance;
}


void App::init() {
  this->m_window = new glimac::SDLWindowManager((uint32_t)this->m_width, (uint32_t )this->m_height, (this->m_title).c_str());

  Utilities::initSDL();
}


void App::start() {
  this->m_running = true;
  this->run();
}

void App::run() {
  glEnable(GL_CULL_FACE);
  glClearColor(0, 0, 0, 0);
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_ALWAYS, 0);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  //glEnable(GL_POLYGON_SMOOTH);
  glEnable(GL_LINE_SMOOTH);
  glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

  SDL_Event ev = {};
  while (this->m_running) {

    while (this->m_window->pollEvent(ev)) {
      if (ev.type == SDL_QUIT) {
        this->stop();
      }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    this->m_window->swapBuffers();

  }
}

void App::stop() {
  this->m_running = false;
}