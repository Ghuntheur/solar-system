#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>

#include <glimac/SDLWindowManager.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>

#include <Sphere.hpp>
#include <Utilities.hpp>

int main(int argc, char** argv) {

  /* -------------------------- */
  /* ----- INITIALIZATION ----- */
  /* -------------------------- */

  glimac::SDLWindowManager windowManager(800, 800, "SolarSystem");

  Utilities::initSDL();

  glimac::FilePath applicationPath(argv[0]);
  glimac::Program program = glimac::loadProgram(
    applicationPath.dirPath() + "shaders/3D.vs.glsl",
    applicationPath.dirPath() + "shaders/normals.fs.glsl"
  );

  program.use();

  /* --------------------- */
  /* ----- MAIN CODE ----- */
  /* --------------------- */


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

    /* ---------------- */
    /* ----- DRAW ----- */
    /* ---------------- */

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUniformMatrix4fv(uMVPMatrixLoc, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
    glUniformMatrix4fv(uMVMatrixLoc, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(uNormalMatrixLoc, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

    sphere.draw();

    // Update the display
    windowManager.swapBuffers();
  }



  return EXIT_SUCCESS;
}
