#include "Objects/Object.hpp"
#include "World/Scene.hpp"

Object::Object(glm::vec3 pos,CustomProgram *program) :
  m_pos(pos), m_program(program) {

  this->m_sphere = new Sphere(0.5f, 32, 16);

}


void Object::attach(Scene *scene) {
  assert(scene != nullptr);
  this->m_scene = scene;
}

void Object::init() {
  this->u_projMatrix = glGetUniformLocation(this->m_program->getGLId(), "uProjMatrix");
  this->u_modelMatrix = glGetUniformLocation(this->m_program->getGLId(), "uModelMatrix");
  this->u_normalMatrix = glGetUniformLocation(this->m_program->getGLId(), "uNormalMatrix");
  this->u_viewMatrix = glGetUniformLocation(this->m_program->getGLId(), "uViewMatrix");
  this->u_texture = glGetUniformLocation(this->m_program->getGLId(), "uTexture");

  this->m_modelMatrix = glm::translate(this->m_baseMatrix, this->m_pos);
  this->m_normalMatrix = glm::transpose(glm::inverse(this->m_modelMatrix));

  this->m_program->use();
  this->m_sphere->initBuffers();
}

void Object::render() {

  /*glUniformMatrix4fv(this->u_MVPMatrix, 1, GL_FALSE, glm::value_ptr(this->m_scene->getProjMatrix()*this->m_MVMatrix));
  glUniformMatrix4fv(this->u_MVMatrix, 1, GL_FALSE, glm::value_ptr(this->m_MVMatrix));
  glUniformMatrix4fv(this->u_NormalMatrix, 1, GL_FALSE, glm::value_ptr(this->m_NormalMatrix));*/

  glUniformMatrix4fv(this->u_projMatrix, 1, GL_FALSE, glm::value_ptr(this->m_scene->getProjMatrix()));
  glUniformMatrix4fv(this->u_viewMatrix, 1, GL_FALSE, glm::value_ptr(this->m_scene->getViewMatrix()));
  glUniformMatrix4fv(this->u_modelMatrix, 1, GL_FALSE, glm::value_ptr(this->m_modelMatrix));
  glUniformMatrix4fv(this->u_normalMatrix, 1, GL_FALSE, glm::value_ptr(this->m_normalMatrix));

  this->m_sphere->binVAO();
  this->m_texture->bind();
  this->m_texture->locate(this->u_texture);
  this->m_sphere->draw();
  this->m_texture->unbind();

}