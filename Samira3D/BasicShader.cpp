#include "BasicShader.h"
#include "ResourceLoader.h"
#include "RenderUtil.h"
using namespace S3D;

BasicShader::BasicShader()
{
	Shader();
	addVertexShader(ResourceLoader::loadTextFile("basicShader.vert"));
	addFragmentShader(ResourceLoader::loadTextFile("basicShader.frag"));
	linkShader();

	addUniform("transform");
	addUniform("color");
}


BasicShader::~BasicShader()
{

}

void BasicShader::updateUniforms(const glm::mat4 &worldMatrix, const glm::mat4 &projectedMatrix, Material *material)
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
	setUniform("color", material->getColor());
}

//test stuff
void BasicShader::updateUniforms(const glm::mat4 &worldMatrix, const glm::mat4 &projectedMatrix)
{
	setUniform("transform", projectedMatrix);
}