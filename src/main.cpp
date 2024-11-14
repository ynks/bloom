#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "keys.h"

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
    glViewport(0, 0, 800, 600);
    while(!glfwWindowShouldClose(window))
    {
    }

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
