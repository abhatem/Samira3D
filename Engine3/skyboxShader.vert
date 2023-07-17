#version 420
layout (location = 0) in vec3 vertexPosition;
out vec3 texCoords;

uniform mat4 CAM_MATRIX;

void main() {
	texCoords = vertexPosition;
	vec4 pos = CAM_MATRIX * vec4(vertexPosition, 1.0);
	gl_Position = pos.xyww;
}