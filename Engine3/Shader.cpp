#include "Shader.h"
#include <fstream>
#include <sstream>
#include <vector>

void Shader::loadFromFile(const std::string & vertexFileName, const std::string & fragmentFileName)
	
{
	m_vertexFileName = vertexFileName;
	m_fragmentFileName = fragmentFileName;
	m_programID = loadShaders();
}

Shader::~Shader()
{
}

void Shader::use() const
{
	glUseProgram(m_programID);
}

void Shader::updateUniformMat4(const std::string & name, const Mat4 &m) const
{
	GLuint matID = glGetUniformLocation(m_programID, name.c_str());
	glUniformMatrix4fv(matID, 1, GL_FALSE, &m[0][0]);
}

void Shader::updateUniformFloat(const std::string & name, const float &f) const
{
	GLuint varID = glGetUniformLocation(m_programID, name.c_str());
	glUniform1fv(varID, 1, &f);
}

void Shader::updateUniformVec3(const std::string & name, const Vec3 & vec3) const
{
	GLuint varID = glGetUniformLocation(m_programID, name.c_str());
	glUniform3fv(varID, 1, &vec3[0]);
}

void Shader::updateUniformMat3(const std::string & name, const glm::mat3 & m) const
{
	GLuint matID = glGetUniformLocation(m_programID, name.c_str());
	glUniformMatrix3fv(matID, 1, GL_FALSE, &m[0][0]);
}

void Shader::updateUniformInt(const std::string & name, GLint i) const
{
	GLuint varID = glGetUniformLocation(m_programID, name.c_str());
	glUniform1i(varID, i);
}

GLuint Shader::loadShaders()
{
	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(m_vertexFileName, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		VertexShaderCode = sstr.str();
		VertexShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", m_vertexFileName.c_str());
		getchar();
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(m_fragmentFileName, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;


	// Compile Vertex Shader
	printf("Compiling shader : %s\n", m_vertexFileName.c_str());
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}



	// Compile Fragment Shader
	printf("Compiling shader : %s\n", m_fragmentFileName.c_str());
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}



	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}


	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}
