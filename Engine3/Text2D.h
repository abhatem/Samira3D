#pragma once
#include "Shader.h"
#include "Font.h"
#include "Globals.h"
class Text2D
{
public:
	Text2D() {};
	void init(Font *f, const std::string & text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
	virtual ~Text2D();
	Font *m_font;
	
	GLfloat m_x, m_y, m_scale;
	glm::vec3 m_color;
	void draw(const Shader &sh);
	void setText(const std::string &text);
	std::string getText() const { return m_text; }
private:
	std::string m_text;

	GLuint VAO, VBO;

	glm::mat4 projection = glm::ortho<float>(0.0f, GLOBAL::width, 0.0f, GLOBAL::height);

};

