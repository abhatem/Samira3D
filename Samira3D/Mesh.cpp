#include <GL\glew.h>
#include "Mesh.h"

using namespace S3D;

Mesh::Mesh()
{
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);
	glGenBuffers(1, &m_tbo);
}


Mesh::~Mesh()
{
}


void Mesh::addVertices(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices)
{
	size = vertices.size();
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	std::vector<float> serial_vertices;
	//std::vector<float> texCoord;
	for (int i = 0; i < vertices.size(); i++)
	{
		serial_vertices.push_back(vertices[i].getPosition().x);
		serial_vertices.push_back(vertices[i].getPosition().y);
		serial_vertices.push_back(vertices[i].getPosition().z);
		m_texCoords.push_back(vertices[i].getTexCoord().x);
		m_texCoords.push_back(vertices[i].getTexCoord().y);
	}

	m_indices = indices;
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * serial_vertices.size(), serial_vertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, m_tbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_texCoords.size(), m_texCoords.data(), GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::addVertices(Vertex* vertices, int length, unsigned int* indices, int ind_length)
{
	size = length;
	
	std::vector<float> serial_vertices;
	for (int i = 0; i < length; i++)
	{
		serial_vertices.push_back(vertices[i].getPosition().x);
		serial_vertices.push_back(vertices[i].getPosition().y);
		serial_vertices.push_back(vertices[i].getPosition().z);
	}
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * serial_vertices.size(), serial_vertices.data(), GL_STATIC_DRAW);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * ind_length, indices, GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void Mesh::draw()
{
	
	//glDrawArrays(GL_TRIANGLES, 0, size);
	//glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, m_tbo);
	glVertexAttribPointer(1, 2, GL_FLOAT, false, 0, (void*)0);
	//glDrawArrays(GL_TRIANGLES, 0, size);
	glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}