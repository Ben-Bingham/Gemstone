#version 330 core

out vec4 FragColor;

in vec4 o_Colour;

void main() {
	FragColor = o_Colour;
}