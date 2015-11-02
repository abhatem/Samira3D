#include "Shader.h"
#include "ERROR.h"
#include <GL\glew.h>
#include <vector>
#include <algorithm>

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


void Shader::bind()
{
	glUseProgram(m_programId);
}

void Shader::addVertexShader(std::string text)
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