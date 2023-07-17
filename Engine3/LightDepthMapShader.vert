#version 420
layout (location = 0) in vec3 vertexPosition;



uniform mat4 MVP_LightSpace;

void main()
{
    gl_Position = MVP_LightSpace * vec4(vertexPosition, 1.0);
	//UV = (vertexPosition.xy+vec2(1,1))/2.0;
}  