#version 330 core

layout (location = 0) in vec3 i_Positon;
layout (location = 1) in vec3 i_Normal;
layout (location = 2) in vec2 i_TextureCords;

uniform mat4 u_MVP;

void main() {
	gl_Position = u_MVP * vec4(i_Positon, 1.0);
}