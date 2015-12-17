#include "Shader.h"
#include "ERROR.h"
#include "WARNING.h"
#include <GL\glew.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <glm/gtc/type_ptr.hpp>

using namespace S3D;

Shader::Shader()
{
	m_programId = glCreateProgram();
	if (m_programId == 0) ERROR(2, "Failed to create shader program");
}


Shader::~Shader()
{
}

/*
Shader::Shader(std::string vertexShader, std::string fragmentShader)
{

}
*/

void Shader::addUniform(std::string uniform)
{
	int uniformLocation = glGetUniformLocation(m_programId, uniform.c_str());

	if (uniformLocation == 0xffffffff) WARNING(1, "could not find uniform: " + uniform);

	m_uniforms.insert(std::pair<std::string, int>(uniform, uniformLocation));
}


void Shader::setUniformi(std::string uniformName, int value)
{
	glUniform1i(m_uniforms[uniformName], value);
}

void Shader::setUniformf(std::string uniformName, float value)
{
	glUniform1f(m_uniforms[uniformName], value);
}

void Shader::setUniform(std::string uniformName, const glm::vec3 &value)
{
	glUniform3f(m_uniforms[uniformName], value.x, value.y, value.z);
}
void Shader::setUniform(std::string uniformName, const glm::mat4 &value)
{
	glUniformMatrix4fv(m_uniforms[uniformName], 1, false, glm::value_ptr(value));
}

void Shader::bind()
{
	glUseProgram(m_programId);
}

void Shader::addVertexShader(const std::string &text)
{
	addProgram(text, GL_VERTEX_SHADER);
}

void Shader::addFragmentShader(std::string text)
{
	addProgram(text, GL_FRAGMENT_SHADER);
}

void Shader::addGeometryShader(std::string text)
{
	addProgram(text, GL_GEOMETRY_SHADER);
}

void Shader::linkShader()
{
	GLint Result = GL_FALSE;
	int InfoLogLength;

	glLinkProgram(m_programId);

	// Check the program
	glGetProgramiv(m_programId, GL_LINK_STATUS, &Result);
	glGetProgramiv(m_programId, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> ProgramErrorMessage(std::max(InfoLogLength, int(1)));
	glGetProgramInfoLog(m_programId, InfoLogLength, NULL, &ProgramErrorMessage[0]);
	//fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
	if (!Result)
		ERROR(3, std::string(ProgramErrorMessage.data()));
}

void Shader::addProgram(std::string text, int type)
{
	GLint Result = GL_FALSE;
	int InfoLogLength;

	unsigned int shader = glCreateShader(type);
	if (!shader) ERROR(2, "Could not create shader");
	char const *c = text.c_str();
	glShaderSource(shader, 1, &c, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &InfoLogLength);
	//std::vector<char> shaderErrorMessage(InfoLogLength);
	std::vector<char> shaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(shader, InfoLogLength, NULL, &shaderErrorMessage[0]);
	//fprintf(stdout, "%s\n", &shaderErrorMessage[0]);
	if (!Result){
		ERROR(3, std::string(shaderErrorMessage.data()));
	}

	glAttachShader(m_programId, shader);
}

void Shader::updateUniforms(const glm::mat4 &worldMatrix, const glm::mat4 &projectedMatrix, Material *material)
{

}