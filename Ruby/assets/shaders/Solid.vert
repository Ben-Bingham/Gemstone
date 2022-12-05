#version 330 core

layout (location = 0) in vec3 inputPositon;
layout (location = 1) in vec3 inputNormal;
layout (location = 2) in vec2 inputTextureCords;

uniform mat4 modelViewProjection;

void main() {
	gl_Position = modelViewProjection * vec4(inputPositon, 1.0);
}