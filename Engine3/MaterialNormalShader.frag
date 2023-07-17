#version 420
out vec4 outColor;


struct Material {
    sampler2D diffuse;
    sampler2D specular;
	sampler2D normalMap;
    float shininess;
}; 
  
uniform Material material;




struct Light {
    vec3 position;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;  

//uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 viewPos;
//uniform float specularIntensity;
//in vec3 normal;

//in vec3 fragmentPosition;
//in vec2 TexCoords;

in VertOut {
	vec3 fragmentPosition;
	vec3 normal;
	vec2 texCoords;
	vec4 fragmentPositionLS; // frag pos in light space
} vertIn;

uniform sampler2D shadowMap;

vec3 lightDirection;
vec3 norm;



void main()
{
	
	vec3 color = texture(material.diffuse, vertIn.texCoords).rgb;
	//norm = normalize(vertIn.normal);
	norm = normalize(texture(material.normalMap, vertIn.texCoords).rgb * 2.0 - 1.0);

	vec3 ambient = 0.15 * color;

	
	lightDirection = normalize(light.position - vertIn.fragmentPosition);
	

	float diff = max(dot(lightDirection, norm), 0.0);
	vec3 diffuse = diff * color;

	//float ambientStrength = 0.1;
    
	vec3 viewDir = normalize(viewPos - vertIn.fragmentPosition); 
	vec3 halfwayDir = normalize(viewDir + lightDirection);
	vec3 reflectDir = reflect(-lightDirection, norm);

	//float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	float spec = pow(max(dot(norm, halfwayDir), 0.0), material.shininess);

	//vec3 specular = light.specular * (spec * texture(material.specular, TexCoords).rgb);
	//vec3 specular = spec * lightColor * texture(material.specular, vertIn.texCoords).rgb;
	//vec3 specular = vec3(spec);
	vec3 specular = vec3(0.2) * spec;
	
	//float shadow = calcShadow(vertIn.fragmentPositionLS);

    vec3 result = (ambient + specular + diffuse);
	//vec3 result = light.position;
	//vec3 result = (ambient + (1.0 - shadow) + diffuse  + specular) * color;
	//vec3 result = (specular) * objectColor;
    outColor = vec4(result, 1.0);
}