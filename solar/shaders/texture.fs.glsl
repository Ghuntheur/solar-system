#version 330 core

in vec2 vTexCoords;

out vec3 fFragColor;

uniform sampler2D uTexture;

void main() {
    fFragColor = texture(uTexture, vTexCoords).rgb;
}