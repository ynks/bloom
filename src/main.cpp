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

  std::unique_ptr<bloom::Engine> bloom = std::make_unique<bloom::Engine>();

  while(!glfwWindowShouldClose(bloom->window))
  {

  }

  // delete the shaders and vertex objects
  vao1.Delete();
  vbo1.Delete();
  ebo1.Delete();
  glDeleteTextures(1, &texture);
  shaderProgram.Delete();

  glfwTerminate();
  return 0;
}
