#pragma once

#include <iostream>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <glimac/glm.hpp>

#include "StateFactory.hpp"
#include "States/StatesEnum.hpp"

class StateFactory;

class State {
  StateFactory *m_controller = nullptr;

public:
  virtual void init(StateFactory *controller);
  virtual ~State();

  virtual void update() = 0;
  virtual void render(double) = 0;
  virtual void keyPressed(uint32_t key, bool active) = 0;
  virtual void mousePressed(uint32_t type, bool active) = 0;
  virtual void stop() = 0;
};

