#include "vao.h"

namespace bloom::vision {

VAO::VAO()
{
  glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO* VBO, unsigned int layout, unsigned int numComponents, GLenum type, GLsizei stride,
    void *offset)
{
  VBO->Bind();
  glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  VBO->Unbind();
}

void VAO::Bind()
{
  glBindVertexArray(ID);
}

void VAO::Unbind()
{
  glBindVertexArray(0);
}

void VAO::Delete()
{
  glDeleteVertexArrays(1, &ID);
}

}
