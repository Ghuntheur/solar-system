#pragma once

#include "World/Scene.hpp"
#include "StateController.hpp"

class StateController;
class Scene;

class PlayState : public State {

private:
  bool m_paused = false;
  bool m_mousePressed = false;
  Scene *m_scene;

public:
  void init(StateController *);
  void pause();
  void resume();
  void stop();
  void render();
  void keyPressed(uint32_t key, bool active);
  void mousePressed(uint32_t type, bool active);
  void mouseMove(const glm::ivec2 &dir);
  void loadMap();
  ~PlayState();

  inline const bool isPaused() const { return this->m_paused; }
};


