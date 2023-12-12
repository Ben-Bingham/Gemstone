#version 330 core
out vec4 FragColor;
  
in vec2 textureCordinates;

uniform sampler2D image;

void main() {
    vec4 color = texture(image, textureCordinates);
    
    if (color.a == 0.0) {
        discard;
    }

    FragColor = color;
}