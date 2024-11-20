#include "renderer.h"

namespace bloom::vision {
Shader* Renderer::GetShader(char* name, char* vert, char* frag)
{
  if (!compiledShaders.contains(name))
  {
    auto _shader = new Shader(vert, frag);
    compiledShaders.insert({name, _shader});
  }

  return compiledShaders.at(name);
}

}
