#include <GL\glew.h>
#include "Mesh.h"

using namespace S3D;

Mesh::Mesh()
{
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);
}


Mesh::~Mesh()
{
}


void Mesh::addVertices(std::vector<Vertex> &vertices)
{
	size = vertices.size();
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	std::vector<float> serial_vertices;
	for (int i = 0; i < vertices.size(); i++)
	{
		serial_vertices.push_back(vertices[i].getPosition().x);
		serial_vertices.push_back(vertices[i].getPosition().y);
		serial_vertices.push_back(vertices[i].getPosition().z);
	}

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * serial_vertices.size(), serial_vertices.data(), GL_STATIC_DRAW);
}

void Mesh::addVertices(Vertex* vertices, int length)
{
	size = length;
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	std::vector<float> serial_vertices;
	for (int i = 0; i < length; i++)
	{
		serial_vertices.push_back(vertices[i].getPosition().x);
		serial_vertices.push_back(vertices[i].getPosition().y);
		serial_vertices.push_back(vertices[i].getPosition().z);
	}

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * serial_vertices.size(), serial_vertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void Mesh::draw()
{
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, size);

	glDisableVertexAttribArray(0);
}