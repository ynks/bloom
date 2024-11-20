/**
 * \file Renderer.h
 * \author Xein <xgonip@gmail.com>
 * \date 11/20/2024
 *
 * \brief Main rendering class
 */

#pragma once
#include <map>
#include <memory>

#include "vao.h"
#include "vbo.h"
#include "ebo.h"
#include "shader.h"

namespace bloom::vision {

class Renderer {

public:
  Renderer();
  ~Renderer();

  // Functions
  Shader* GetShader(const char* name, const char* vert, const char* frag);
  void DeleteShader(const char* name);

  // Variables
    
    
private:
  std::map<std::string, Shader*> compiledShaders;
    
};

}
