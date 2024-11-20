#include "actor.h"

#include "vision/renderer.h"

namespace bloom {

Actor::Actor()
{
  _vao = new vision::VAO;
  _vbo = new vision::VBO(vertices, sizeof(vertices));
  _ebo = new vision::EBO(indices, sizeof(indices));

  _shader = bloom->GetRenderer()->GetShader("defaultShader", vision::DEFAULT_VERT, vision::DEFAULT_FRAG);
}

Actor::~Actor()
{
  _vao->Delete();
  _vbo->Delete();
  _ebo->Delete();

  delete _vao;
  delete _vbo;
  delete _ebo;
  delete _shader;
}

void Actor::Render() {}

void Actor::Begin()
{
  Object::Begin();

  // Link attributes from vertices to the VAO
  _vao->Bind();
  _vao->LinkAttrib(_vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)nullptr); // Positions
  _vao->LinkAttrib(_vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float))); // UVs
  _vao->Unbind();
  _vbo->Unbind();
  _ebo->Unbind();

  // xTODO: Texture things
  _shader->Activate();
}

}
