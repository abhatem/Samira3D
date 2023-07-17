#version 420

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec3 vertexTangent;
layout(location = 3) in vec2 texCoords;

uniform mat4 MVP;
uniform mat4 modelMat;
uniform mat3 normalMat;

struct DirectionalLight {
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform mat4 lightSpaceProjView;

out VertOut {
	vec3 fragmentPosition;
	vec3 normal;
	vec2 texCoords;
	vec4 fragmentPositionLS; // frag pos in light space
	
	vec3 tangentLightPosition;
	vec3 tangentViewPosition;
	vec3 tangentFragmentPosition;
	vec3 lightPosition;

	
} vertOut;

#define NR_DIRECTIONAL_LIGHTS 1

uniform DirectionalLight directionalLights[NR_DIRECTIONAL_LIGHTS];

out DirectionalLight directionalLightsTBN[NR_DIRECTIONAL_LIGHTS];

uniform vec3 lightPosition;
uniform vec3 viewPos;

flat out int numDirectionalLights;

void main(){
	numDirectionalLights = NR_DIRECTIONAL_LIGHTS;
	//vec3 T = normalize(vec3(modelMat * vec4(vertexTangent, 0.0)));
	//vec3 N = normalize(vec3(modelMat * vec4(vertexNormal, 0.0)));
	//vec3 B = cross(N, T);
	vec3 T = normalize(normalMat * vertexTangent);
	vec3 N = normalize(normalMat * vertexNormal);
	T = normalize(T - dot(T, N) * N);
	vec3 B = cross(N, T);
	mat3 TBN = transpose(mat3(T, B, N));
	vertOut.fragmentPosition = vec3(modelMat * vec4(vertexPosition_modelspace, 1.0));
	vertOut.normal = normalMat * vertexNormal;
	vertOut.texCoords = texCoords;
	vertOut.fragmentPositionLS = lightSpaceProjView * vec4(vertOut.fragmentPosition, 1.0);

	vertOut.tangentLightPosition = TBN * lightPosition;
	vertOut.tangentViewPosition = TBN  * viewPos;
	vertOut.tangentFragmentPosition = TBN * vertOut.fragmentPosition;

	for(int i = 0; i < NR_DIRECTIONAL_LIGHTS; ++i) {
		directionalLightsTBN[i].diffuse = directionalLights[i].diffuse;
		directionalLightsTBN[i].specular = directionalLights[i].specular;
		directionalLightsTBN[i].ambient = directionalLights[i].ambient;
		directionalLightsTBN[i].direction = directionalLights[i].direction;
	}

	gl_Position = MVP * vec4(vertexPosition_modelspace, 1);
  
  //normal = vertexNormal;
}
