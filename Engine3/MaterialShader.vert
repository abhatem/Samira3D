#version 420

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec2 texCoords;
out vec3 normal;
uniform mat4 MVP;
uniform mat4 modelMat;
uniform mat3 normalMat;
out vec3 fragmentPosition; 
out vec2 TexCoords;

uniform mat4 lightSpaceProjView;

out VertOut {
	vec3 fragmentPosition;
	vec3 normal;
	vec2 texCoords;
	vec4 fragmentPositionLS; // frag pos in light space
} vertOut;

void main(){

	vertOut.fragmentPosition = vec3(modelMat * vec4(vertexPosition_modelspace, 1.0));
	vertOut.normal = normalMat * vertexNormal;
	vertOut.texCoords = texCoords;
	vertOut.fragmentPositionLS = lightSpaceProjView * vec4(vertOut.fragmentPosition, 1.0);
	gl_Position = MVP * vec4(vertexPosition_modelspace, 1);
  
  //normal = vertexNormal;
}
