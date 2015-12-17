#include "PhongShader.h"
#include "ResourceLoader.h"
#include "RenderUtil.h"
using namespace S3D;

PhongShader::PhongShader()
{
	Shader();
	addVertexShader(ResourceLoader::loadTextFile("phongShader.vert"));
	addFragmentShader(ResourceLoader::loadTextFile("phongShader.frag"));
	linkShader();

	addUniform("transform");
	addUniform("baseColor");
	addUniform("ambientLight");
}


PhongShader::~PhongShader()
{

}

void PhongShader::updateUniforms(const glm::mat4 &worldMatrix, const glm::mat4 &projectedMatrix, Material *material)
{
	if (material->getTexture() != NULL)
	{
		material->getTexture()->bind();
	}
	else
	{
		RenderUtil::setTexturesEnabled(false);
	}
	setUniform("transform", projectedMatrix);
	setUniform("baseColor", material->getColor());
	setUniform("ambientLight", m_ambientLight);
}

//test stuff
void PhongShader::updateUniforms(const glm::mat4 &worldMatrix, const glm::mat4 &projectedMatrix)
{
	setUniform("transform", projectedMatrix);
}