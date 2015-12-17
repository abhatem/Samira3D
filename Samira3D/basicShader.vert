#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 color_in;
//layout(location = 2) in vec3 color;
//layout(location = 3) in vec3 tangent;
//layout(location = 4) in vec3 normal;

//out vec4 color;
out vec2 texCoord0;

//uniform float uFloat;

uniform mat4 transform;
/*uniform mat4 translation;
uniform mat4 rotation;
uniform mat4 scale;
*/
/*uniform mat4 projectionMat;
uniform mat4 CameraMat;
*/
//mat4 transform;

void main()
{
	//transform = translation * rotation * scale;
	//mat4 transform = projectionMat * CameraMat;
	//color = vec4(clamp(position, 0.0, 1.0), 1.0);
	//color = vec4(color_in, 1);
	gl_Position = transform * vec4(0.5 * position, 1.0);
	texCoord0 = texCoord;
}