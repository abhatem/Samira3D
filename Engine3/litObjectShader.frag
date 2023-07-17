#version 420
out vec4 outColor;


uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 viewPos;
uniform float specularIntensity;
in vec3 normal;

in vec3 fragmentPosition;

void main()
{
	
	vec3 norm = normalize(normal);
	vec3 lightDirection = normalize(lightPosition - fragmentPosition);
	vec3 viewDir = normalize(viewPos - fragmentPosition);
	vec3 reflectDir = reflect(-lightDirection, norm);

	float diff = max(dot(norm, lightDirection), 0.0);
	vec3 diffuse = diff * lightColor;

	float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 2);
	vec3 specular = specularIntensity * spec * lightColor;

    vec3 result = (specular + ambient + diffuse) * objectColor;
	//vec3 result = (specular) * objectColor;
    outColor = vec4(result, 1.0);
}