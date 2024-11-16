/**
 * \file vbo.h
 * \author Xein <xgonip@gmail.com>
 * \date 15/11/2024
 *
 * \brief Vertex Buffer Object file
 */

#pragma once
#include <glad/glad.h>

namespace bloom::vision {

class VBO {
public:
  unsigned int ID;
  VBO (float* vertices, GLsizeiptr size);

  void Bind();
  void Unbind();
  void Delete();
};

}
