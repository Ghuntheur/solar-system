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
      if (e.type == SDL_QUIT) {
        this->stop();
      }

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      this->m_stateController->render();
      this->m_window->swapBuffers();

    }
  }

  /* glimac::Program program = glimac::loadProgram(
    App::s_appPath + "shaders/3D.vs.glsl",
    App::s_appPath + "shaders/texture.fs.glsl"
  );

  program.use();

  Sphere sphere(1, 32, 16);

  Texture earth(App::s_appPath + "assets/earth.jpg");

  GLint uMVPMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
  GLint uMVMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVMatrix");
  GLint uNormalMatrixLoc = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
  GLint uTextureLoc = glGetUniformLocation(program.getGLId(), "uTexture");

  glm::mat4 ProjMatrix, MVMatrix, NormalMatrix, MoonMVMatrix;
  ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/800.f, 0.1f, 100.f);
  MVMatrix = glm::translate(MVMatrix, glm::vec3(0.f, 0.f, -5.f));
  NormalMatrix = glm::transpose(MVMatrix);

  sphere.initBuffers();
  
  SDL_Event ev = {};
  while (this->m_running) {

    while (this->m_window->pollEvent(ev)) {
      if (ev.type == SDL_QUIT) {
        this->stop();
      }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUniformMatrix4fv(uMVPMatrixLoc, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
    glUniformMatrix4fv(uMVMatrixLoc, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(uNormalMatrixLoc, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

    sphere.binVAO();
    earth.bind();
    earth.locate(uTextureLoc);
    sphere.draw();
    earth.unbind();

    this->m_window->swapBuffers();

  } */
}

void App::stop() {
  this->m_running = false;
}