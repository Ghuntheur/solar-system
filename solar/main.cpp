#define GLEW_STATIC
#include <iostream>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <glimac/SDLWindowManager.hpp>

#include "App.hpp"
#include "Render/Sphere.hpp"
#include "Render/Texture.hpp"

int main(int argc, char** argv) {

  /*glimac::FilePath appPath(argv[0]);

  App * app = App::instance();

  try {
    app->init();
    app->start();
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  delete app;

  return EXIT_SUCCESS;*/
  glimac::SDLWindowManager windowManager(800, 800, "GLImac");

  Utilities::initSDL();

  glimac::FilePath applicationPath(argv[0]);
  glimac::Program program = loadProgram(
    applicationPath.dirPath() + "shaders/3D.vs.glsl",
    applicationPath.dirPath() + "shaders/texture.fs.glsl"
  );

  program.use();

  Sphere sphere(1, 32, 16);

  Texture earth("./assets/earth.jpg");

  GLint uMVPMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
  GLint uMVMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVMatrix");
  GLint uNormalMatrixLoc = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
  GLint uTextureLoc = glGetUniformLocation(program.getGLId(), "uTexture");

  glm::mat4 ProjMatrix, MVMatrix, NormalMatrix, MoonMVMatrix;
  ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/800.f, 0.1f, 100.f);
  MVMatrix = glm::translate(MVMatrix, glm::vec3(0.f, 0.f, -5.f));
  NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

  sphere.initBuffers();

  glEnable(GL_DEPTH_TEST);

  bool done = false;
  while (!done) {

    SDL_Event e;
    while (windowManager.pollEvent(e)) {
      if (e.type == SDL_QUIT) {
        done = true;
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

    // Update the display
    windowManager.swapBuffers();
  }

  earth.remove();
  return EXIT_SUCCESS;
}
