#version 330 core

out vec4 FragColor;

uniform sampler2D ambient;

in vec2 textureCords;

void main() {
	FragColor = texture(ambient, textureCords);
}
