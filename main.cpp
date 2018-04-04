#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>

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

  /* --------------------- */
  /* ----- MAIN CODE ----- */
  /* --------------------- */

  return EXIT_SUCCESS;
}