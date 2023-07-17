#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &m_vertexBufferID);
	glDeleteVertexArrays(1, &m_vertexArrayID);
}

void Mesh::init(const std::vector<GLfloat> &bufferData)
{
	m_bufferData = bufferData;
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	glGenBuffers(1, &m_vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, m_bufferData.size() * sizeof(GLfloat), m_bufferData.data(), GL_STATIC_DRAW);
}

void Mesh::draw()
{
	glBindVertexArray(m_vertexArrayID);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
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
		8 * sizeof(GLfloat),                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size, number of components per generic vertex attribute
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		8 * sizeof(GLfloat),                  // stride
		(void*)(3*sizeof(GLfloat))            // array buffer offset
	);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(
		2,                  
		2,                  
		GL_FLOAT,           
		GL_FALSE,          
		8 * sizeof(GLfloat),                  
		(void*)(6 * sizeof(GLfloat))            
	);
	glEnableVertexAttribArray(2);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, m_bufferData.size() / 8);
	glDisableVertexAttribArray(0);
}
