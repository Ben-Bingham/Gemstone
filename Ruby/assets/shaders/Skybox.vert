#version 330 core
layout (location = 0) in vec3 inputPositon;
layout (location = 1) in vec3 inputNormal;
layout (location = 2) in vec2 inputTextureCords;
out vec3 textureCordinates;

uniform mat4 viewProjection;

void main() {
    textureCordinates = inputPositon;
    vec4 pos = viewProjection * vec4(inputPositon, 1.0);
    gl_Position = pos.xyww;
}  