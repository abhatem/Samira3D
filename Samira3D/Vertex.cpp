#include "Vertex.h"

using namespace S3D;

Vertex::Vertex()
{
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_normal = glm::vec3(0.0f, 0.0f, 0.0f);
	m_tangent = glm::vec3(0.0f, 0.0f, 0.0f);
	m_color = glm::vec3(0.0f, 0.0f, 0.0f);
	m_texCoord = glm::vec2(0.0f, 0.0f);
}

Vertex::Vertex(glm::vec3 position)
{
	m_position = position;
	m_color = DEFAULT_COLOR;
}

Vertex::Vertex(glm::vec3 position, glm::vec2 texCoord)
{
	m_position = position;
	m_texCoord = texCoord;
	m_color = DEFAULT_COLOR;
}

Vertex::Vertex(glm::vec3 position, glm::vec3 color)
{
	m_position = position;
	m_color = color;
}


Vertex::~Vertex()
{
}
