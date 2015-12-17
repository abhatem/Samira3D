#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 color_in;
//layout(location = 2) in vec3 color;
//layout(location = 3) in vec3 tangent;
//layout(location = 4) in vec3 normal;


out vec2 texCoord0;

uniform mat4 transform;


void main()
{
	gl_Position = transform * vec4(position, 1.0);
	texCoord0 = texCoord;
}