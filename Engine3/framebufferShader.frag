#version 330 core
out vec3 color;

in vec2 UV;

uniform sampler2D renderedTexture;
uniform float time;

void main(){
  //color = texture( renderedTexture, UV + 0.005*vec2( sin(time+800.0*UV.x),cos(time+600.0*UV.y))).xyz;
  color = texture( renderedTexture, UV ).xyz;
}