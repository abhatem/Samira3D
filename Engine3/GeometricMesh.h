#pragma once
#include <GL/glew.h>
#include <vector>
// only vertex postions (no normals, uvs, tangents, ...)
class GeometricMesh {
public:

	GeometricMesh();
	virtual ~GeometricMesh();

	void init(const std::vector<GLfloat> &bufferData);

	void draw();

private:
	GLuint m_vertexArrayID;
	GLuint m_vertexBufferID;
	std::vector<GLfloat> m_bufferData;



};
#pragma once
