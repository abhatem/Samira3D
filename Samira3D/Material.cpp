#include "Material.h"

using namespace S3D;

Material::Material(TEXTURE texture, glm::vec3 color)
{
	m_texture = texture;
	m_color = color;
}


Material::~Material()
{
}
