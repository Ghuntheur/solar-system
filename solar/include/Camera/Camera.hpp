#pragma once

#include <glimac/glm.hpp>

class Camera {

protected:
  static unsigned int s_uid;
  const unsigned int UID = s_uid++;

  glm::vec3 m_position;
  float m_fov = 45.0f;

public:
  void setPosition(float x, float y, float z);
  void setPosition(glm::vec3 &pos);

  virtual glm::mat4 getViewMatrix() const = 0;

  inline void setFov(const float fov) { this->m_fov = fov; }

  inline const glm::vec3 getPosition() const { return this->m_position; }
  inline const float getFov() const { return this->m_fov; }
  inline const unsigned int getUID() const { return Camera::UID; }

  bool operator ==(const Camera &camera) {
    return camera.getUID() == Camera::UID;
  }



};
