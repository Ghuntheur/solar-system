#pragma once

#include <iostream>
#include <map>
#include <assert.h>

#include "States/State.hpp"
#include "App.hpp"

class StateFactory {

private:
  AppState m_current = PLAY_STATE;
  std::map<int, State*> m_app_states;

public:
  StateFactory();
  ~StateFactory();

  void add(int, State *);
  void update();
  void render(double);
  void keyPressed(uint32_t, bool);
  void mousePressed(uint32_t, bool);
  void setState(AppState);
  void stop();

  inline const AppState getAppState() const { return this->m_current; }

};

