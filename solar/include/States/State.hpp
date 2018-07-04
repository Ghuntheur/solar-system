#pragma once

#include <glimac/glm.hpp>

#include "StateController.hpp"

class StateController;

class State {

protected:
  glm::ivec2 m_mousePos;
  StateController *m_controller = nullptr;

public:
  virtual void init(StateController* controller) {
    this->m_controller = controller;
  }
  virtual void render() = 0;
  virtual void keyPressed(uint32_t key, bool active) = 0;
  virtual void mousePressed(uint32_t type, bool active) = 0;
  virtual void mouseMove(const glm::ivec2 &dir) = 0;
  virtual void stop() = 0;
  virtual ~State() = default;

  void setMousePos(const glm::ivec2 &pos) {
    this->m_mousePos = pos;
  }

};


