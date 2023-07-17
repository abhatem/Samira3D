#pragma once
#include <GL/glew.h>
#include <vector>
class Mesh {
public:

	Mesh();
	virtual ~Mesh();

	void init(const std::vector<GLfloat> &bufferData);

	void draw();
	
private:
	GLuint m_vertexArrayID;
	GLuint m_vertexBufferID;
	std::vector<GLfloat> m_bufferData;
	


};
