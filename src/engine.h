//
// Created by Xein on 12/11/2024.
// xgonip@gmail.com
//

#pragma once
#include "GLFW/glfw3.h"

namespace bloom {

/**
 * \class Engine
 * \brief A class that represents the main engine for the bloom application.
 */
class Engine {

    GLFWwindow* window; ///< Pointer to the GLFW window instance.

    /**
     * \brief Processes input for the given window.
     * \param window Pointer to the GLFW window instance.
     */
    void processInput(GLFWwindow* window);

public:
    /**
     * \brief Constructs an Engine object with the given window.
     * \param w Pointer to the GLFW window instance.
     */
    explicit Engine(GLFWwindow* w);

    /**
     * \brief Updates the engine state.
     */
    void Update();

    /**
     * \brief Renders the engine output.
     */
    void Render();
};

}