#include "engine.h"

namespace bloom {

Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::Begin(const int width, const int height, const char* title)
{
  // Initialize OpenGL
  if (!glfwInit())
  {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    throw std::runtime_error("Failed to initialize GLFW");
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create window object
  window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (window == nullptr)
  {
    std::cerr << "Failed to create window" << std::endl;
    glfwTerminate();
    throw std::runtime_error("Failed to create window");
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

  // GLAD initialization
  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
  {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    throw std::runtime_error("Failed to initialize GLAD");
  }

  // Main loop
  glViewport(0, 0, width, height);

  // Render shit
  vao1.Bind();

  vision::VBO vbo1(vertices, sizeof(vertices));
  vision::EBO ebo1(indices, sizeof(indices));

  vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
  vao1.LinkAttrib(vbo1, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
  vao1.Unbind();
  vbo1.Unbind();
  ebo1.Unbind();

  int widthImage, heightImage, numColCh;
  unsigned char* image = stbi_load("resources/textures/cat.png", &widthImage, &heightImage, &numColCh, 4);

  unsigned int texture;
  glGenTextures(1, &texture);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImage, heightImage, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(image);
  glBindTexture(GL_TEXTURE_2D, 0);

  unsigned int tex0Uniform = glGetUniformLocation(shaderProgram.ID, "tex0");
  shaderProgram.Activate();
}

void Engine::Update()
{
  // input
  ProcessInput(window);

  // render
  glClearColor(0.11f, 0.11f, 0.11f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // use the shader to render the triangle
  shaderProgram.Activate();
  glBindTexture(GL_TEXTURE_2D, texture);
  vao1.Bind();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

  // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
  glfwSwapBuffers(window);
  glfwPollEvents();
}

void Engine::Render()
{

}

void Engine::Destroy()
{

}

/**
 * Callback function for when the framebuffer is resized.
 * Adjusts the viewport of the OpenGL context to the new window dimensions.
 *
 * @param window The GLFW window that was resized.
 * @param width The new width of the window.
 * @param height The new height of the window.
 */
void Engine::FramebufferSizeCallback(GLFWwindow* window, const int width, const int height)
{
  glViewport(0, 0, width, height);
}

/**
 * \brief Processes input for the given window.
 * \param window Pointer to the GLFW window instance.
 */
void Engine::ProcessInput(GLFWwindow *window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

}
