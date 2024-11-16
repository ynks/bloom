#include "shader.h"

namespace bloom::vision {

std::string GetFileContents(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (file)
    {
        std::string contents;
        file.seekg(0, std::ios::end);
        contents.resize(file.tellg());
        file.seekg(0, std::ios::beg);
        file.read(&contents[0], contents.size());
        file.close();
        return contents;
    }

    std::cerr << "Failed to open file " << filename << std::endl;
    return "error";
}

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    std::string vertexCode = GetFileContents(vertexPath);
    std::string fragmentCode = GetFileContents(fragmentPath);

    const char* vertexSource = vertexCode.c_str();
    if (*vertexSource == *"error") vertexSource = vertexShaderFallback;

    const char* fragmentSource = fragmentCode.c_str();
    if (*fragmentSource == *"error")
      fragmentSource = fragmentShaderFallback;

    // Compile shaders
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);

    // Create shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    // We delete the shaders as they are already on the program
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
    glUseProgram(ID);
}

void Shader::Delete()
{
    glDeleteProgram(ID);
}


}