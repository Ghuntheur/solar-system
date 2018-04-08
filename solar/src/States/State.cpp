#include "states/State.hpp"

virtual void State::init(StateFactory *controller) {
  this->m_controller = controller;
}

virtual void State::~State() { }