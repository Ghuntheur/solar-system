#version 330 core

// Sommets
layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoords;

// Matrices
uniform mat4 uProjMatrix;
uniform mat4 uModelMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uNormalMatrix;

// Sorties
out vec2 vTexCoords;

void main() {
    vTexCoords = aVertexTexCoords;
    gl_Position = uProjMatrix * uViewMatrix * uModelMatrix * vec4(aVertexPosition.xyz, 1);;
}
