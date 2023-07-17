#version 420

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;
out vec3 normal;
uniform mat4 MVP;
uniform mat4 modelMat;
uniform mat3 normalMat;
out vec3 fragmentPosition; 
void main(){
  gl_Position = MVP * vec4(vertexPosition_modelspace, 1);
  fragmentPosition = vec3(modelMat * vec4(vertexPosition_modelspace, 1.0));
  normal = normalMat * vertexNormal;
}
