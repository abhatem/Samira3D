#pragma once

#include <string>
#include <map>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include "Material.h"


typedef struct ShaderInfo
{
	unsigned int ProgramID;
	std::string FileName;
} ShaderInfo;

namespace S3D {

	class Shader
	{
	public:
		Shader();
		~Shader();

		//Shader(std::string vertexShader, std::string fragmentShader);

		void linkShader();
		void bind();

		void addUniform(std::string uniform);
		void setUniformi(std::string uniformName, int value);
		void setUniformf(std::string uniformName, float value);
		void setUniform(std::string uniformName, const glm::vec3 &value);
		void setUniform(std::string uniformName, const glm::mat4 &value);

		void addVertexShader(const std::string &vertexShader);
		void addFragmentShader(std::string fragmentShader);
		void addGeometryShader(std::string goemetryShader);

		virtual void updateUniforms(const glm::mat4 &worldMatrix, const glm::mat4 &projectedMatrix, Material *material);


	private:

		void addProgram(std::string text, int type);

		std::string m_vertexShader;
		std::string m_fragmentShader;
		std::string m_geometryShader;

		unsigned int m_programId;

		std::map<std::string, int> m_uniforms;
	};

}
