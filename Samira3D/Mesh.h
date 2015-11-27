#pragma once
#include <vector>
#include "Vertex.h"
namespace S3D 
{

	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		void addVertices(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices);
		void addVertices(Vertex* vertices, int length, unsigned int *indices, int ind_length);

		void draw();

	private:
		unsigned int m_vbo;
		unsigned int m_ibo;
		unsigned int m_tbo;
		unsigned int size;
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_indices;
		std::vector<float> m_serializedVertPos;
		std::vector<float> m_texCoords;
		//std::vector<glm::vec2> m_texCoords;
	};
}

