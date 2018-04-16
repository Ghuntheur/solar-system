#include "Objects/Object.hpp"

Object::Object(CustomProgram *program) {
  this->m_program = program;
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
}

void Object::render() {

}