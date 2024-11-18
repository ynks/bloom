#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <iostream>
#include <memory>

#include "bloom/engine.h"

// Function prototypes
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{

  bloom::Engine bloom{};
  bloom.Begin(800, 800, "bloom-engine");

  while(!glfwWindowShouldClose(bloom.window))
  {
    bloom.Update();
    bloom.Render();
  }

  bloom.Destroy();
  return 0;
}
