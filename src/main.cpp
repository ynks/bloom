#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

#include "keys.h"
#include "bloom/vision/shader.h"
#include "bloom/vision/vao.h"
#include "bloom/vision/vbo.h"
#include "bloom/vision/ebo.h"

// Function prototypes
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
  // Initialize OpenGL
  if (!glfwInit())
  {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Square vertices
  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f,
    0.5f,  0.5f, 0.0f,

  };

  unsigned int indices[] = {
    0, 1, 2,
    1, 2, 3
  };

  // Create window object
  GLFWwindow* window = glfwCreateWindow(Keys::Engine::SCR_WIDTH, Keys::Engine::SCR_HEIGHT, Keys::Engine::SCR_TITLE, nullptr, nullptr);
  if (window == nullptr)
  {
    std::cerr << "Failed to create window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // GLAD initialization
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // Main loop
  glViewport(0, 0, Keys::Engine::SCR_WIDTH, Keys::Engine::SCR_HEIGHT);

  bloom::vision::Shader shaderProgram("../resources/shaders/default.vert", "../resources/shaders/default.frag");

  bloom::vision::VAO vao1;
  vao1.Bind();

  bloom::vision::VBO vbo1(vertices, sizeof(vertices));
  bloom::vision::EBO ebo1(indices, sizeof(indices));

  vao1.LinkVBO(vbo1, 0);
  vao1.Unbind();
  vbo1.Unbind();
  ebo1.Unbind();


  while(!glfwWindowShouldClose(window))
  {
    // input
    processInput(window);

    // render
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // use the shader to render the triangle
    shaderProgram.Activate();
    vao1.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // delete the shaders and vertex objects
  vao1.Delete();
  vbo1.Delete();
  ebo1.Delete();
  shaderProgram.Delete();

  glfwTerminate();
  return 0;
}

/**
 * Callback function for when the framebuffer is resized.
 * Adjusts the viewport of the OpenGL context to the new window dimensions.
 *
 * @param window The GLFW window that was resized.
 * @param width The new width of the window.
 * @param height The new height of the window.
 */
void framebuffer_size_callback(GLFWwindow* window, const int width, const int height)
{
  glViewport(0, 0, width, height);
}

/**
 * \brief Processes input for the given window.
 * \param window Pointer to the GLFW window instance.
 */
void processInput(GLFWwindow *window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}
