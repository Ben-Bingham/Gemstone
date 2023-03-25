#version 330 core

out vec4 FragColor;

uniform vec3 objectColour;

void main() {
	FragColor = vec4(objectColour, 1.0);
}
