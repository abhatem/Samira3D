#pragma once
#include <string>
#include <GL/glew.h>
#include "Transform.h"
class Shader {
public:
	Shader() {}
	void loadFromFile(const std::string &vertexFileName, const std::string &fragmentFileName);
	virtual ~Shader();
	void use() const;
	GLuint getID() const { return m_programID; }
	std::string getVertexFileName() const { return m_vertexFileName; }
	std::string getFragmentFileName() const { return m_fragmentFileName; }
	void updateUniformMat4(const std::string &name, const Mat4 &m) const;
	void updateUniformFloat(const std::string &name, const float &f) const;
	void updateUniformVec3(const std::string &name, const Vec3 &vec3) const;
	void updateUniformMat3(const std::string &name, const glm::mat3 &m) const;
	void updateUniformInt(const std::string &name, GLint i) const;
private:
	GLuint m_programID;
	std::string m_vertexFileName;
	std::string m_fragmentFileName;
	GLuint loadShaders();
	
};