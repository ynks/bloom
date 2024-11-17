#version 450 core

// Layouts
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aUV;

// Inputs

// Outputs
out vec2 UV;

void main() {
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    UV = aUV;
}