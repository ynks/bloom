/**
 * \file ebo.h
 * \author Xein <xgonip@gmail.com>
 * \date 15/11/2024
 *
 * \brief Element Array Buffer Object file
 */

#pragma once
#include <glad/glad.h>

namespace bloom::vision {

class EBO {
public:
  unsigned int ID;
  EBO (unsigned int* indices, GLsizeiptr size);

  void Bind();
  void Unbind();
  void Delete();
};

}
