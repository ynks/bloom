/**
 * \file vao.h
 * \author Xein <xgonip@gmail.com>
 * \date 15/11/2024
 *
 * \brief Vertex Array Object file
 */

#pragma once
#include "VBO.h"

namespace bloom::vision {

class VAO {
public:
  unsigned int ID;
  VAO();

  void LinkVBO(VBO VBO, unsigned int layout);
  void Bind();
  void Unbind();
  void Delete();
};

}
