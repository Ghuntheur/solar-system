#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>

#include <App.hpp>



App *App::s_instance = nullptr;

App::App() { }

int App::initSDL() {
  GLenum glewInitError = glewInit();
  if(GLEW_OK != glewInitError) {
    std::cerr << glewGetErrorString(glewInitError) << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

  return EXIT_SUCCESS;
}

App *App::instance() {
  if (!s_instance) {
    s_instance = new App;
  }
  return App::s_instance;
}

App::~App() {
  delete this->m_window;
}

/* -------------------------------- */

void App::init(const std::string title, const int width, const int height) {
  this->setTitle(title);
  this->setWindowWidth(width);
  this->setWindowHeight(height);

  this->m_window = new glimac::SDLWindowManager((uint32_t)this->m_width, (uint32_t)this->m_width, this->m_title.c_str());

  this->initSDL();

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


  while (this->m_running) {
    SDL_Event e;
    while (this->m_window->pollEvent(e)) {
      if (e.type == SDL_QUIT) {
        this->stop();
      }
    }
  }
}

void App::stop() {
  this->m_running = false;
}