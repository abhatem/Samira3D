#pragma once
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

// the color that should be rendered at default if no other color or
// texture is specified
#define DEFAULT_COLOR glm::vec3(0.7, 0.7, 0.7)

namespace S3D {
	class Vertex
	{
	public:
		Vertex();
		~Vertex();

		Vertex(glm::vec3 position);
		Vertex(glm::vec3 position, glm::vec2 texCoord);
		Vertex(glm::vec3 position, glm::vec3 color);

		glm::vec3 getPosition() { return m_position; }
		glm::vec3 getNormal() { return m_normal; }
		glm::vec3 getTangent() { return m_tangent; }
		glm::vec3 getColor() { return m_color; }
		glm::vec2 getTexCoord() { return m_texCoord; }
		
		void setPosition(glm::vec3 position) { m_position = position; }
		void setNormal(glm::vec3 normal) { m_normal = normal; }
		void setTangent(glm::vec3 tangent) { m_tangent = tangent; }
		void setColor(glm::vec3 color) { m_color = color; }
		void setTexCoord(glm::vec2 texCoord) { m_texCoord = texCoord; }

	private:
		glm::vec3 m_position; // position in 3d space
		glm::vec3 m_normal; // the normal of the vertex (used with normal maps)
		glm::vec3 m_tangent; // the tangent of the vertex (will determine the direction of the face)
		glm::vec3 m_color; // the color of the vertex (should be used when there is no texture)
		glm::vec2 m_texCoord; // the UV coordinates in the texture
	};
}

