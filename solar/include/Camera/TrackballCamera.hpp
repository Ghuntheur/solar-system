#pragma once

#include <glimac/glm.hpp>

#include "Camera/Camera.hpp"

class TrackballCamera : public Camera {

private:
  float m_fDistance = 0.0f;
  float m_fAngleX = 0.0f;
  float m_fAngleY = 0.0f;

  float m_minLeftClamp = 0.0f;
  float m_maxLeftClamp = 0.0f;
  float m_minUpClamp = 0.0f;
  float m_maxUpClamp = 0.0f;

public:
  TrackballCamera() = default;

  void moveFront(float delta);
  void rotateLeft(float degrees) override;
  void rotateUp(float degrees) override;
  void clampUp(float min, float max);
  void clampLeft(float min, float max);
  glm::mat4 getViewMatrix() const override;

  inline void setDistance(const float distance) { this->m_fDistance = distance; }
  inline void setAngleUp(const float angle) { this->m_fAngleX = angle; }
  inline void setAngleLeft(const float angle) { this->m_fAngleY = angle; }

  inline float getDistance() const { return this->m_fDistance; }
  inline float getAnglex() const { return this->m_fAngleX; }
  inline float getAngleY() const { return this->m_fAngleY; }
};