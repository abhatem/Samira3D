#pragma once

#include <vector>
#include <string>
#include <GL/glew.h>
#include "GeometricMesh.h"
#include "Shader.h"
#include "CameraAbstract.h"
class Skybox {
public:
	Skybox();
	void init(const std::string &right, const std::string &left,
		const std::string &top, const std::string &bottom,
		const std::string &front, const std::string &back);

	void draw(CameraAbstract *cam, Shader &sh);

private:
	GLuint m_textureID;
	std::vector<GLfloat> m_vertices;
	GLuint vao, vbo;
	GeometricMesh m_mesh;
};