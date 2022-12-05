#version 330 core
layout (location = 0) in vec3 inputPositon;
layout (location = 1) in vec3 inputNormal;
layout (location = 2) in vec2 inputTextureCords;

out vec2 textureCordinates;

uniform mat4 model;

void main() {
    textureCordinates = inputTextureCords;

    gl_Position = model * vec4(inputPositon, 1.0);
}  