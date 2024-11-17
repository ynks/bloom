#version 450 core

// Inputs
in vec2 UV;

// Outputs
out vec4 FragColor;

// Uniforms
uniform sampler2D tex0;

void main() {
    // I prefer to show UVs on the R and B coordinates rather than on the R and G
    // It's prettier that way
    FragColor = texture(tex0, UV);
}