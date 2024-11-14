//
// Created by Xein on 12/11/2024.
// xgonip@gmail.com
//

#pragma once
#include <GLFW/glfw3.h>

namespace bloom {

/// \class Engine
/// \brief Main engine class.
class Engine {

    GLFWwindow* window; ///< Pointer to the GLFW window instance.

    /**
     * \brief Processes input for the given window.
     * \param window Pointer to the GLFW window instance.
     */
    void processInput(GLFWwindow* window);

public:
    /// Constructor.
    /// @param w Pointer to the GLFW window instance.
    explicit Engine(GLFWwindow* w);

    /// \brief Update phase of the engine.
    void Update();

    /// \brief Render phase of the engine.
    void Render();
};

}