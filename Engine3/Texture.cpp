#include "Texture.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Texture::Texture()
{
	
}

bool Texture::loadFromFile(const std::string & name)
{
	sf::Image imgData;
	
	if (!imgData.loadFromFile(name)) {
		std::cout << "cant load " << name << std::endl;
		return false;
	}
	
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);
	
	glTexImage2D(
		GL_TEXTURE_2D, 0, GL_RGBA,
		imgData.getSize().x, imgData.getSize().y,
		0,
		GL_RGBA, GL_UNSIGNED_BYTE, imgData.getPixelsPtr()
	);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return true;
}

void Texture::bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture::bind(GLuint slot)
{
	glActiveTexture(GL_TEXTURE0+slot);
	glBindTexture(GL_TEXTURE_2D, m_id);
}
