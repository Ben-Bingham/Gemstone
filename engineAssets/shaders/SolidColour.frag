#version 330 core

out vec4 FragColor;

uniform vec3 u_Colour;

void main() {
	FragColor = vec4(u_Colour, 1.0);
}
