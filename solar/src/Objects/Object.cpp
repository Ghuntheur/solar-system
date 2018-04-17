#include "Objects/Object.hpp"
#include "World/Scene.hpp"

Object::Object(glm::vec3 pos,CustomProgram *program) :
  m_pos(pos), m_program(program) {

  this->m_sphere = new Sphere(1, 32, 16);

}


void Object::attach(Scene *scene) {
  assert(scene != nullptr);
  this->m_scene = scene;
}

void Object::init() {
  this->u_MVPMatrix = glGetUniformLocation(this->m_program->getGLId(), "uMVPMatrix");
  this->u_MVMatrix = glGetUniformLocation(this->m_program->getGLId(), "uMVMatrix");
  this->u_NormalMatrix = glGetUniformLocation(this->m_program->getGLId(), "uNormalMatrix");
  this->u_Texture = glGetUniformLocation(this->m_program->getGLId(), "uTexture");

  this->m_MVMatrix = glm::translate(this->m_MVMatrix, this->m_pos);

  this->m_program->use();
  this->m_sphere->initBuffers();
}

void Object::render() {


  glUniformMatrix4fv(this->u_MVPMatrix, 1, GL_FALSE, glm::value_ptr(this->m_scene->getProjMatrix()*this->m_MVMatrix));
  glUniformMatrix4fv(this->u_MVMatrix, 1, GL_FALSE, glm::value_ptr(this->m_MVMatrix));
  glUniformMatrix4fv(this->u_NormalMatrix, 1, GL_FALSE, glm::value_ptr(this->m_NormalMatrix));

  this->m_sphere->binVAO();
  this->m_texture->bind();
  this->m_texture->locate(this->u_Texture);
  this->m_sphere->draw();
  this->m_texture->unbind();

}