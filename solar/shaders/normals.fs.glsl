#version 330 core

// Entrées
in vec3 vNormal_vs;

// Sorties
out vec3 fFragColor;

void main() {
    fFragColor = normalize(vNormal_vs);
}