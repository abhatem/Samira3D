#version 330

out vec4 fragColor;

in vec2 texCoord0;

uniform vec3 baseColor;
uniform vec3 ambientLight;
uniform sampler2D sampler;

void main()
{
	vec4 textureColor = texture2D(sampler, texCoord0.xy) * vec4(baseColor, 1);

	vec4 totalLight = vec4(ambientLight, 1);

	vec4 color = vec4(baseColor, 1);
	//fragColor = vec4(1.0, 0.0, 0.0, 1.0);

	color *= textureColor;


	fragColor = color * totalLight;

	//fragColor = vec4(1, 1, 1, 1);
}