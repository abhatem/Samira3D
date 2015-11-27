#include "Texture.h"
#include <GL\glew.h>

using namespace S3D;

Texture::Texture(int id)
{
	m_id = id;
}


Texture::~Texture()
{
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}


