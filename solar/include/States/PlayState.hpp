#pragma once

#include "State.hpp"

class PlayState : public State {

private:
  bool m_paused = false;
  bool m_mouse_pressed = false;
  Scene *m_scene;

public:


  inline const bool isPaused() const { return this->m_paused; }

};


