#version 420

out vec4 outColor;


struct Material {
    sampler2D diffuseMap;
    sampler2D specularMap;
	sampler2D normalMap;
    float shininess;
}; 
  
uniform Material material;

//uniform vec3 objectColor;
uniform vec3 lightColor;
//uniform vec3 lightPosition;
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
	//mat3 TBN;
	vec3 tangentLightPosition;
	vec3 tangentViewPosition;
	vec3 tangentFragmentPosition;
	vec3 lightPosition;
} vertIn;



uniform sampler2D shadowMap;

vec3 lightDirection;
vec3 norm;

struct DirectionalLight {
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in DirectionalLight directionalLightsTBN[1];
flat in int numDirectionalLights;

vec3 calcDirectionalLight(DirectionalLight dirLight, vec3 normal, vec3 viewDir) 
{
	vec3 lightDir = normalize(-dirLight.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
	vec3 halfwayDir = normalize(viewDir + lightDirection);
	vec3 reflectDir = reflect(-lightDirection, normal);

    float spec = pow(max(dot(viewDir, halfwayDir), 0.0), material.shininess);
    // combine results
    vec3 ambient  = dirLight.ambient  * vec3(texture(material.diffuseMap, vertIn.texCoords));
    vec3 diffuse  = dirLight.diffuse  * diff * vec3(texture(material.diffuseMap, vertIn.texCoords));
    vec3 specular = dirLight.specular * spec * vec3(texture(material.specularMap, vertIn.texCoords));
    return (ambient + diffuse + specular);
}

float calcShadow(vec4 fragmentPositionLS) {

	lightDirection = normalize(vertIn.lightPosition - vertIn.fragmentPosition);
	norm = normalize(vertIn.normal);
	float bias = max(0.0005 * (1.0 - dot(norm, lightDirection)), 0.00005);
	//bias = 0.00005;
	vec3 projCoords = fragmentPositionLS.xyz / fragmentPositionLS.w;
	projCoords = projCoords * 0.5 + 0.5; 

	if(projCoords.z > 1.0) return 0.0;


	float closestDepth = texture(shadowMap, projCoords.xy).r;
	float currentDepth = projCoords.z; 
	float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0; 
	
	vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
	for(int x = -1; x <= 1; ++x)
	{
		for(int y = -1; y <= 1; ++y)
		{
			float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r; 
			shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;        
		}    
	}
	shadow /= 9.0;
	return shadow;
}



void main()
{
	
	vec3 color = texture(material.diffuseMap, vertIn.texCoords).rgb;
	norm = texture(material.normalMap, vertIn.texCoords).rgb;
	norm = normalize(norm * 2.0 - 1.0);
	//norm = normalize(vertIn.TBN * norm);

	vec3 ambient = 0.15 * color;

	
	lightDirection = normalize(vertIn.tangentLightPosition - vertIn.tangentFragmentPosition);
	

	float diff = max(dot(lightDirection, norm), 0.0);
	vec3 diffuse = diff * lightColor * color;

	//float ambientStrength = 0.1;
    
	vec3 viewDir = normalize(vertIn.tangentViewPosition - vertIn.tangentFragmentPosition); 
	vec3 halfwayDir = normalize(viewDir + lightDirection);
	vec3 reflectDir = reflect(-lightDirection, norm);

	//float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	float spec = pow(max(dot(norm, halfwayDir), 0.0), material.shininess);

	//vec3 specular = light.specular * (spec * texture(material.specular, TexCoords).rgb);
	vec3 specular = spec * lightColor * texture(material.specularMap, vertIn.texCoords).rgb;
	
	float shadow = calcShadow(vertIn.fragmentPositionLS);
	//vec3 result = (ambient + (1.0 - shadow) * (diffuse + specular));
	vec3 result = vec3(0.0f);
	for(int i = 0; i < numDirectionalLights; ++i) {
		result += calcDirectionalLight(directionalLightsTBN[i], norm, viewDir) / float(numDirectionalLights);
	}

	//vec3 result = (ambient + specular + diffuse) * color;
	//vec3 result = color;
	
	//vec3 result = (ambient + (1.0 - shadow) + diffuse  + specular) * color;
	//vec3 result = (specular) * objectColor;
    outColor = vec4(result, 1.0);
}