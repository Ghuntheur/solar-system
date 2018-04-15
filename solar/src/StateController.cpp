#include "StateController.hpp"

void StateController::add(const int key, State *state) {
  state->init(this);
  this->m_gameStates.insert(std::make_pair(key, state));
}

void StateController::render() {
  this->m_gameStates[this->m_current]->render();
}

void StateController::keyPressed(const uint32_t key, const bool active) {
  this->m_gameStates[this->m_current]->keyPressed(key, active);
}

void StateController::mousePressed(const uint32_t key, const bool active) {
  this->m_gameStates[this->m_current]->mousePressed(key, active);
}

void StateController::mouseMove(glm::ivec2 &pos, glm::ivec2 &dir) {
  this->m_gameStates[this->m_current]->setMousePos(pos);
  this->m_gameStates[this->m_current]->mouseMove(dir);
}

void StateController::setState(AppStates index) {
  if (index < 0 || (int)this->m_gameStates.size()-1) {
    throw std::runtime_error("State index out of bound");
  }
  this->m_current = index;
}

void StateController::stop() {
  this->m_gameStates[this->m_current]->stop();
}

StateController::~StateController() {
  for (const auto &temp : this->m_gameStates) {
    delete temp.second;
  }
}