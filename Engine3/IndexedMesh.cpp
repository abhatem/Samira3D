#include "IndexedMesh.h"

IndexedMesh::IndexedMesh()
{

}

IndexedMesh::~IndexedMesh()
{
	glDeleteBuffers(1, &m_vertexBufferID);
	glDeleteBuffers(1, &m_indexBufferID);
	glDeleteVertexArrays(1, &m_vertexArrayID);

}

void IndexedMesh::init(const std::vector<Vertex> &vertices, const std::vector<GLuint> indices)
{
	m_vertices = vertices;
	m_indices = indices;
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	glGenBuffers(1, &m_vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &m_indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), indices.data(), GL_STATIC_DRAW);

}

void IndexedMesh::draw()
{
	glBindVertexArray(m_vertexArrayID);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferID);
	//glVertexAttribPointer(
	//	0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	//	3,                  // size, number of components per generic vertex attribute
	//	GL_FLOAT,           // type
	//	GL_FALSE,           // normalized?
	//	0,                  // stride
	//	(void*)0            // array buffer offset
	//);

	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size, number of components per generic vertex attribute
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		sizeof(Vertex),                  // stride
		(void*)offsetof(Vertex, position)            // array buffer offset
	);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size, number of components per generic vertex attribute
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		sizeof(Vertex),                  // stride
		(void*)offsetof(Vertex, normal)            // array buffer offset
	);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(
		2,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size, number of components per generic vertex attribute
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		sizeof(Vertex),                  // stride
		(void*)offsetof(Vertex, tangent)            // array buffer offset
	);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(
		3,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		2,                  // size, number of components per generic vertex attribute
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		sizeof(Vertex),                  // stride
		(void*)offsetof(Vertex, texCoords)            // array buffer offset
	);
	glEnableVertexAttribArray(3);

	// Draw the triangle !
	//glDrawArrays(GL_TRIANGLES, 0, m_bufferData.size() / 8);
	glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, (void*)0);
	glDisableVertexAttribArray(0);
}
