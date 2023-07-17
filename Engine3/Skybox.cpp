#include "Skybox.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Skybox::Skybox() {
	m_vertices = {
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f,  1.0f
	};
}

void Skybox::init(const std::string & right, const std::string & left, const std::string & top, const std::string & bottom, const std::string & front, const std::string & back)
{

	m_mesh.init(m_vertices);


	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);
	

	sf::Image imgData;
	if (!imgData.loadFromFile(right)) {
		std::cout << "cant load " << right << std::endl;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X,
		0, GL_RGBA, imgData.getSize().x, imgData.getSize().y,
		0, GL_RGBA, GL_UNSIGNED_BYTE, imgData.getPixelsPtr());


	if (!imgData.loadFromFile(left)) {
		std::cout << "cant load " << left << std::endl;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+1,
		0, GL_RGBA, imgData.getSize().x, imgData.getSize().y,
		0, GL_RGBA, GL_UNSIGNED_BYTE, imgData.getPixelsPtr());


	if (!imgData.loadFromFile(top)) {
		std::cout << "cant load " << top << std::endl;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 2,
		0, GL_RGBA, imgData.getSize().x, imgData.getSize().y,
		0, GL_RGBA, GL_UNSIGNED_BYTE, imgData.getPixelsPtr());


	if (!imgData.loadFromFile(bottom)) {
		std::cout << "cant load " << bottom << std::endl;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 3,
		0, GL_RGBA, imgData.getSize().x, imgData.getSize().y,
		0, GL_RGBA, GL_UNSIGNED_BYTE, imgData.getPixelsPtr());


	if (!imgData.loadFromFile(front)) {
		std::cout << "cant load " << front << std::endl;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 4,
		0, GL_RGBA, imgData.getSize().x, imgData.getSize().y,
		0, GL_RGBA, GL_UNSIGNED_BYTE, imgData.getPixelsPtr());


	if (!imgData.loadFromFile(back)) {
		std::cout << "cant load " << back << std::endl;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 5,
		0, GL_RGBA, imgData.getSize().x, imgData.getSize().y,
		0, GL_RGBA, GL_UNSIGNED_BYTE, imgData.getPixelsPtr());

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}


void Skybox::draw(CameraAbstract *cam, Shader &sh)
{
	
	glDepthFunc(GL_LEQUAL);
	sh.use();
	sh.updateUniformMat4("CAM_MATRIX", cam->projection() * glm::mat4(glm::mat3(cam->view()))); // view has translation removed.
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);
	m_mesh.draw();
	glDepthFunc(GL_LESS);
}
