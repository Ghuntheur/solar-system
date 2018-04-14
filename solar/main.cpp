#define GLEW_STATIC
#include <iostream>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <glimac/SDLWindowManager.hpp>

#include "App.hpp"
#include "Render/Sphere.hpp"
#include "Render/Texture.hpp"

int main(int argc, char** argv) {

  glimac::FilePath appPath(argv[0]);

  App *app = App::instance();
  App::s_appPath = appPath.dirPath();

  try {
    app->init();
    app->start();
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  delete app;

  return EXIT_SUCCESS;
}
