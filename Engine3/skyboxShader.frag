#version 420

out vec3 color;

in vec3 texCoords;

uniform samplerCube tex;

void main() {
	color = texture(tex, texCoords).rgb;
}