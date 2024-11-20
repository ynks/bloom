#include "renderer.h"

namespace bloom::vision {

Shader* Renderer::GetShader(const char* name, const char* vert, const char* frag)
{
  if (!compiledShaders.contains(name))
  {
    auto _shader = new Shader(vert, frag);
    compiledShaders.insert({name, _shader});
  }

  return compiledShaders[name];
}

void Renderer::DeleteShader(const char *name)
{
  const auto _shader = compiledShaders[name];
  if (_shader == nullptr)
  {
    std::cout << "Shader " << name << " not found" << std::endl;
    return;
  }

  _shader->Delete();
  compiledShaders.erase(name);
}
}
