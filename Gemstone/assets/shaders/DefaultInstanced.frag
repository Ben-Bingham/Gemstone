#version 330 core

out vec4 FragColor;

uniform sampler2D u_Diffuse;
uniform sampler2D u_Specular;

in vec2 o_Uv;

void main() {
	FragColor = vec4(mix(texture(u_Diffuse, o_Uv), texture(u_Specular, o_Uv), 0.5).xyz, 1.0);
}