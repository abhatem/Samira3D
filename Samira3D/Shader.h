#pragma once

#include <string>


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

		void addVertexShader(std::string vertexShader);
		void addFragmentShader(std::string fragmentShader);
		void addGeometryShader(std::string goemetryShader);


	private:

		void addProgram(std::string text, int type);

		std::string m_vertexShader;
		std::string m_fragmentShader;
		std::string m_geometryShader;

		unsigned int m_programId;
	};

}
