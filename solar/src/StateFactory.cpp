#include "StateFactory.hpp"

StateFactory::StateFactory() { }

void StateFactory::add(const int key, State *state) {
  state->init(this);
  this->m_app_states.insert(std::make_pair(key, state));
}

void StateFactory::update() {
  assert(this->m_app_states[this->m_current] != nullptr);
  this->m_app_states[m_current]->update();
}

void StateFactory::render(double delta) {
  assert(this->m_app_states[this->m_current] != nullptr);
  this->m_app_states[this->m_current]->render(delta);
}

void StateFactory::keyPressed(const uint32_t key, const bool active) {
  assert(this->m_app_states[this->m_current] != nullptr);
  this->m_app_states[this->m_current]->keyPressed(key, active);
}

void StateFactory::mousePressed(const uint32_t key, const bool active) {
  assert(this->m_app_states[this->m_current] != nullptr);
  this->m_app_states[this->m_current]->mousePressed(key, active);
}

void StateFactory::setState(AppState index) {
  if (index < 0 || index > (int)this->m_app_states.size()-1) {
    throw std::runtime_error("State index out of bound");
  }
  this->m_current = index;
}

void StateFactory::stop() {
  assert(this->m_app_states[this->m_current] != nullptr);
  this->m_app_states[this->m_current]->stop();
}

void StateFactory::~StateFactory() {
  for (const auto &temp : this->m_app_states) {
    delete temp.second;
  }
}