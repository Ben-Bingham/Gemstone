#version 330 core

layout (location = 0) in vec3 l_Position;
layout (location = 1) in vec3 l_Normal;
layout (location = 2) in vec2 l_Uv;
layout (location = 3) in vec3 I_Offset;

out vec2 o_Uv;

uniform mat4 u_MVP;

void main() {
	o_Uv = l_Uv;

	gl_Position = u_MVP * vec4(l_Position + I_Offset, 1.0);
}