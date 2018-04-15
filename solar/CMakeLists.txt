cmake_minimum_required(VERSION 3.9)
project(solarSystem)

set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)
#set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)

add_definitions(-std=c++11)

file(GLOB_RECURSE SOURCE_FILES *.cpp)
file(GLOB_RECURSE HEADER_FILES *.hpp)
file(GLOB_RECURSE SHADER_FILES *.glsl)

set(SOURCE_FILES ${SOURCE_FILES} ${HEADER_FILES} ${SHADER_FILES})

include_directories(include)

add_executable(solarSystem ${SOURCE_FILES})
target_link_libraries(solarSystem ${ALL_LIBRARIES})

file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/assets)
file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/shaders)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
