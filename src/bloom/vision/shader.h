/**
 * \file shader.h
 * \author Xein <xgonip@gmail.com>
 * \date 15/11/2024
 *
 * \brief This file contains the shader class
 */

#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

namespace bloom::vision {

std::string GetFileContents(const std::string& filename);

class Shader {

#pragma region Fallback Shaders

  const char* vertexShaderFallback = R"(
#version 450 core
layout (location = 0) in vec3 aPos;
void main() {
  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
)";
  const char* fragmentShaderFallback = R"(
#version 450 core
out vec4 FragColor;
void main() {
  FragColor = vec4(1.0f, 0.0f, 1.0f, 1.0f);
}
)";

#pragma endregion

public:
    unsigned int ID;
    Shader(const char* vertexPath, const char* fragmentPath);

    void Activate();
    void Delete();
};

}
