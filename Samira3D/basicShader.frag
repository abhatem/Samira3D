#version 330

out vec4 fragColor;
//in vec4 color;
in vec2 texCoord0;

uniform sampler2D sampler;

uniform vec3 color;

void main()
{
	fragColor = texture2D(sampler, texCoord0.xy) * vec4(color, 1);
	//fragColor = vec4(1.0, 0.0, 0.0, 1.0);

	//fragColor = color;
}