#pragma once

#include <map>

#include "States/State.hpp"
#include "States/AppStates.hpp"

class StateController {

private:
  AppStates m_current = PLAY_STATE;
  std::map<int, State*> m_gameStates;

public:
  StateController() = default;
  ~StateController();

  void add(int, State *);
  void render();
  void keyPressed(uint32_t, bool);
  void mousePressed(uint32_t, bool);
  void mouseMove(const glm::ivec2 &, const glm::ivec2 &);
  void setState(AppStates);
  void stop();

  inline const AppStates getState() const { return this->m_current; }

};


