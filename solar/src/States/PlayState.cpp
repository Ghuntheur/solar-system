#include "States/PlayState.hpp"

void PlayState::init(StateController *controller) {
  State::init(controller);

  this->m_scene = new Scene;
  this->m_scene->init();
  this->m_scene->loadPlanets();
}

void PlayState::render() {
  this->m_scene->render();
}

void PlayState::keyPressed(const uint32_t key, const bool active) {

}

void PlayState::mousePressed(const uint32_t type, const bool active) {
  if (type == SDL_BUTTON_LEFT) {
    this->m_mousePressed = active;
  }
  this->m_scene->mousePressed(type, active);
}

void PlayState::mouseMove(const glm::ivec2 &dir) {
  if (this->m_mousePressed) {
    this->m_scene->mouseMove(dir);
  }
}

void PlayState::stop() {

}

PlayState::~PlayState() {
  delete this->m_scene;
}