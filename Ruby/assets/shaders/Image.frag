#version 330 core
out vec4 FragColor;
  
in vec2 textureCordinates;

uniform sampler2D image;

void main() { 
    float depthValue = texture(image, textureCordinates).r;
    FragColor = vec4(vec3(depthValue), 1.0);
}