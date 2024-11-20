/**
 * \file Actor.h
 * \author Xein <xgonip@gmail.com>
 * \date 11/20/2024
 *
 * \brief [Brief description of the file's purpose]
 */

#pragma once
#include "object.h"
#include "vision/vao.h"
#include "vision/vbo.h"
#include "vision/ebo.h"
#include "vision/shader.h"

namespace bloom {

class Actor : Object {

public:
  Actor();

  // Functions
  virtual void Render();
  void Begin() override;
    
  // Variables
    
    
private:
  // Variables
  // Render things
  vision::Shader* _shader;
  vision::VAO* _vao;
  vision::VBO* _vbo;
  vision::EBO* _ebo;

  // Vertex shit
  // Square vertices
  float vertices[20] = {
    // x      y     z     U     V
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
     0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
  };

  unsigned int indices[6] = {
    0, 1, 2,
    1, 2, 3
  };
    
};

}
