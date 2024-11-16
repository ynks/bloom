#include "ebo.h"

namespace bloom::vision {
    
EBO::EBO(unsigned int *vertices, GLsizeiptr size)
{
  glGenBuffers(1, &ID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void EBO::Bind()
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
  glDeleteBuffers(1, &ID);
}
    
}