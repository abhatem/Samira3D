#version 420
layout(location = 0) in vec3 vertexPosition_modelspace;
//layout(location = 1) in vec2 vertexUV;
out vec2 UV;
void main(){
  gl_Position.xyz = vertexPosition_modelspace;
  gl_Position.w = 1.0;
  UV = (vertexPosition_modelspace.xy+vec2(1,1))/2.0;
}
