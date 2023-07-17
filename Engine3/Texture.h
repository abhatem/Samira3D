#pragma once

#include <GL/glew.h>
#include <string>

class Texture {
public:
	Texture();
	bool loadFromFile(const std::string &name);
	void bind();
	void bind(GLuint slot);
	GLuint getID() const { return m_id; }
	void setID(GLuint id) { m_id = id; }

private:
	GLuint m_id;
};