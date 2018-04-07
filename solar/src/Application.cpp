#define GLEW_STATIC

#include <iostream>
#include <string>
#include <GL/glew.h>

#include <Application.hpp>

Application *Application::m_instance = nullptr;

Application::Application() { }

int Application::initSDL() {
  GLenum glewInitError = glewInit();
  if(GLEW_OK != glewInitError) {
    std::cerr << glewGetErrorString(glewInitError) << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

  return EXIT_SUCCESS;
}

void Application::init(const std::string title, const int widthh, const int height) {

}