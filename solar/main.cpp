#define GLEW_STATIC
#include <iostream>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <App.hpp>

#include "Vendors/Utilities.hpp"
#include "Render/Sphere.hpp"

int main(int argc, char** argv) {

  App * app = App::instance();
  app->init();
  app->start();

  /*glimac::SDLWindowManager windowManager(800, 800, "GLImac");

  Utilities::initSDL();

  glimac::FilePath applicationPath(argv[0]);
  glimac::Program program = loadProgram(
    applicationPath.dirPath() + "shaders/3D.vs.glsl",
    applicationPath.dirPath() + "shaders/normals.fs.glsl"
  );

  program.use();


  Sphere sphere(1, 32, 16);

  GLint uMVPMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
  GLint uMVMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVMatrix");
  GLint uNormalMatrixLoc = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

  glEnable(GL_DEPTH_TEST);

  glm::mat4 ProjMatrix, MVMatrix, NormalMatrix;
  ProjMatrix = glm::perspective(glm::radians(120.f), 800.f/800.f, 0.1f, 100.f);

  MVMatrix = glm::translate(MVMatrix, glm::vec3(0.f, 0.f, -5.f));

  NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

  sphere.initBuffers();

  bool done = false;
  while (!done) {

    SDL_Event e;
    while (windowManager.pollEvent(e)) {
      if (e.type == SDL_QUIT) {
        done = true;
      }
    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 test = glm::rotate(test, windowManager.getTime(), glm::sphericalRand(5.f));

    glUniformMatrix4fv(uMVPMatrixLoc, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
    glUniformMatrix4fv(uMVMatrixLoc, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(uNormalMatrixLoc, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

    sphere.draw();

    // Update the display
    windowManager.swapBuffers();
  } */
}
