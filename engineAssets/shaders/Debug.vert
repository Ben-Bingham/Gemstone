#version 330 core

layout (location = 0) in vec3 i_Positon;

uniform mat4 u_Matrix;

void main() {
	gl_Position = u_Matrix * vec4(i_Positon, 1.0);
}