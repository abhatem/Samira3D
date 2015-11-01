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

		void addVertices(std::vector<Vertex> &vertices);
		void addVertices(Vertex* vertices, int length);

		void draw();

	private:
		unsigned int m_vbo;
		unsigned int m_ibo;
		unsigned int size;
		std::vector<Vertex*> m_vertices;
		std::vector<unsigned int> m_indices;
	};
}

