cmake_minimum_required(VERSION 2.8)

project(ImacGL)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include third-party/include solar/include)

#set(ALL_LIBRARIES glimac custom ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} glu32 freeglut)
set(ALL_LIBRARIES mingw32 glimac solar SDL glew32s opengl32 glu32 freeglut) #add the libraries options in the LIB_LIST variable
add_subdirectory(glimac)
add_subdirectory(solar)

file(GLOB_RECURSE SHADER_FILES shaders/*.glsl)

set(OUTPUT SolarSystem)
add_executable(${OUTPUT} main.cpp ${SHADER_FILES})
target_link_libraries(${OUTPUT} ${ALL_LIBRARIES})

file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})