#version 330 core

layout (location = 0) in vec3 l_Position;
layout (location = 1) in vec3 l_Normal;
layout (location = 2) in vec2 l_Uv;

void main() {
	gl_Position = vec4(l_Position, 1.0);
}