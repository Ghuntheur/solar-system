#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/Sphere.hpp>
#include <VBO.hpp>
#include <VAO.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>

int main(int argc, char** argv) {

  /* -------------------------- */
  /* ----- INITIALIZATION ----- */
  /* -------------------------- */

  glimac::SDLWindowManager windowManager(800, 800, "SolarSystem");

  GLenum glewInitError = glewInit();
  if(GLEW_OK != glewInitError) {
    std::cerr << glewGetErrorString(glewInitError) << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;


  glimac::FilePath applicationPath(argv[0]);
  glimac::Program program = glimac::loadProgram(
    applicationPath.dirPath() + "shaders/3D.vs.glsl",
    applicationPath.dirPath() + "shaders/normals.fs.glsl"
  );

  program.use();

  /* --------------------- */
  /* ----- MAIN CODE ----- */
  /* --------------------- */


  glimac::Sphere sphere(1, 32, 16);

  GLint uMVPMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
  GLint uMVMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVMatrix");
  GLint uNormalMatrixLoc = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

  glEnable(GL_DEPTH_TEST);

  glm::mat4 ProjMatrix, MVMatrix, NormalMatrix;
  ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/800.f, 0.1f, 100.f);

  MVMatrix = glm::translate(MVMatrix, glm::vec3(0.f, 0.f, -5.f));

  NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

  VBO vbo = VBO();
  vbo.bind();
  vbo.addVertices(sphere.getVertexCount(), sphere.getDataPointer());
  vbo.unbind();

  VAO vao = VAO();
  vao.bind();
  vao.enableVertex(3, 0, 1, 2, 3);
  vao.setOffset(3, 3, 3, 2);

  vbo.bind();
  vao.attribVertex(GL_FLOAT);
  vbo.unbind();
  vao.unbind();

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

    vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

    // Update the display
    windowManager.swapBuffers();
  }



  return EXIT_SUCCESS;
}
