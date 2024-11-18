/**
 * \file engine.h
 * \author Xein <xgonip@gmail.com>
 * \date 16/11/2024
 *
 * \brief Main engine class file
 */

#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "keys.h"
#include "vision/ebo.h"
#include "vision/shader.h"
#include "vision/vao.h"
#include "vision/vbo.h"
#include "stb/stb_image.h"

namespace bloom {

class Engine {

  // Functions
  void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
  void ProcessInput(GLFWwindow *window);

  // Square vertices
  float vertices[] = {
    // x      y     z     U     V
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
     0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
  };

  unsigned int indices[] = {
    0, 1, 2,
    1, 2, 3
  };

  vision::Shader shaderProgram("resources/shaders/default.vert", "resources/shaders/default.frag");
  vision::VAO vao1;

public:
  Engine();
  ~Engine();

  // Functions
  void Begin(int width, int height, const char* title);
  void Update();
  void Render();
  void Destroy();

  // Variables
  GLFWwindow* window;
};

}
