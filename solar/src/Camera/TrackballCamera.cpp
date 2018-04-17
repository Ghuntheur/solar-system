#include "Camera/TrackballCamera.hpp"

void TrackballCamera::moveFront(float delta) {
  this->m_fDistance += delta;
}

void TrackballCamera::rotateLeft(float degrees) {
  this->m_fAngleY += degrees;
  if (this->m_minLeftClamp !=0 && this->m_fAngleY < this->m_minLeftClamp) { this->m_fAngleY = this->m_minLeftClamp; }
  if (this->m_maxLeftClamp !=0 && this->m_fAngleY > this->m_maxLeftClamp) { this->m_fAngleY = this->m_maxLeftClamp; }
}

void TrackballCamera::rotateUp(float degrees) {
  this->m_fAngleX += degrees;
  if (this->m_minUpClamp !=0 && this->m_fAngleX < this->m_minUpClamp) { this->m_fAngleX = this->m_minUpClamp; }
  if (this->m_maxUpClamp !=0 && this->m_fAngleX < this->m_maxUpClamp) { this->m_fAngleX = this->m_maxUpClamp; }
}

void TrackballCamera::clampUp(const float min, const float max) {
  this->m_minUpClamp = min;
  this->m_maxUpClamp = max;
}

void TrackballCamera::clampLeft(const float min, const float max) {
  this->m_minLeftClamp = min;
  this->m_maxLeftClamp = max;
}

glm::mat4 TrackballCamera::getViewMatrix() const {
  glm::mat4 mat = glm::mat4(1.0f);
  mat = glm::translate(mat, glm::vec3(0, 0, this->m_fDistance));
  mat = glm::rotate(mat, glm::radians(this->m_fAngleX), glm::vec3(1, 0, 0));
  mat = glm::rotate(mat, glm::radians(this->m_fAngleY), glm::vec3(0, 1, 0));
  mat = glm::translate(mat, this->m_position);
  return mat;
}