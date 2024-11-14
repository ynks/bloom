//
// Created by Xein on 12/11/2024.
// xgonip@gmail.com
//

#include "engine.h"

namespace bloom
{
    Engine::Engine(GLFWwindow* w)
    {
        window = w;
    }

    void Engine::Update()
    {
        // input
        processInput(window);
    }

    void Engine::Render()
    {
        // render
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Engine::processInput(GLFWwindow *window) {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
}
