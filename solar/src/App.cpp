#define GLEW_STATIC

#include <glimac/Program.hpp>
#include <Render/Sphere.hpp>
#include <Render/Texture.hpp>
#include "App.hpp"


App *App::s_instance = nullptr;
glimac::FilePath App::s_appPath = "";

App::App() = default;

App *App::instance() {
  if (!s_instance) {
    s_instance = new App;
  }
  return s_instance;
}


void App::init() {
  this->m_stateController = new StateController();

  this->m_window = new glimac::SDLWindowManager(
    (uint32_t) this->m_width,
    (uint32_t) this->m_height,
    (this->m_title).c_str()
  );
  Utilities::initSDL();

  this->m_stateController->add(PLAY_STATE, new PlayState);

  this->m_stateController->setState(PLAY_STATE);

}

void App::start() {
  this->m_running = true;
  this->run();
}

void App::run() {
  glEnable(GL_DEPTH_TEST);

  while (this->m_running) {

    SDL_Event e = {};
    while (this->m_window->pollEvent(e)) {

      switch (e.type) {

        case SDL_QUIT:
          this->stop();
          break;

        case SDL_MOUSEBUTTONDOWN:
          this->m_stateController->mousePressed(e.button.button, true);
          break;

        case SDL_MOUSEBUTTONUP:
          this->m_stateController->mousePressed(e.button.button, false);
          break;

        case SDL_KEYDOWN:
          this->m_stateController->keyPressed(e.key.keysym.sym, true);
          if (e.key.keysym.sym == SDLK_ESCAPE) {
            this->stop();
            // TODO: stop static func
          }
          break;

        case SDL_KEYUP:
          this->m_stateController->keyPressed(e.key.keysym.sym, false);
          break;

        case SDL_MOUSEMOTION:
          this->m_stateController->mouseMove(glm::ivec2(e.motion.x, e.motion.y), glm::ivec2(e.motion.xrel, e.motion.yrel));
          break;

        default:
          break;

      }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->m_stateController->render();
    this->m_window->swapBuffers();
  }

}

void App::stop() {
  this->m_running = false;
}

float App::getTime() {
  return this->m_window->getTime();
}