#pragma once
#pragma once
#include <GL/glew.h>
#include <vector>
#include "Vertex.h"

class IndexedMesh {
public:

	IndexedMesh();
	virtual ~IndexedMesh();

	void init(const std::vector<Vertex> &vertices, const std::vector<GLuint> indices);

	void draw();

private:
	GLuint m_indexBufferID;
	GLuint m_vertexArrayID;
	GLuint m_vertexBufferID;
	//std::vector<GLfloat> m_bufferData; // maybe not needed after sending to gpu.
	std::vector<Vertex> m_vertices;
	std::vector<GLuint> m_indices; // maybe not needed after sending to gpu.



};
