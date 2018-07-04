#include "Camera/Camera.hpp"

unsigned int Camera::s_uid = 0;

void Camera::setPosition(float x, float y, float z) {
  this->m_position.x = x;
  this->m_position.y = y;
  this->m_position.z = z;
}

void Camera::setPosition(const glm::vec3 &pos) {
  this->m_position = pos;
}