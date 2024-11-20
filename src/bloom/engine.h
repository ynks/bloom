/**
 * \file engine.h
 * \author Xein <xgonip@gmail.com>
 * \date 16/11/2024
 *
 * \brief Main engine class file
 */

#pragma once
#include <iostream>
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "keys.h"
#include "vision/ebo.h"
#include "vision/shader.h"
#include "vision/vao.h"
#include "vision/vbo.h"
#include "stb/stb_image.h"
#include "vision/renderer.h"

namespace bloom {

class Engine {

  // Functions
  static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
  void ProcessInput(GLFWwindow *window);

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

  vision::Shader* shaderProgram;
  vision::VAO* vao1;
  vision::VBO* vbo1;
  vision::EBO* ebo1;
  unsigned int texture;

  std::unique_ptr<vision::Renderer> renderer;

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
  [[nodiscard]] vision::Renderer* GetRenderer() const { return renderer.get(); }
};

}
