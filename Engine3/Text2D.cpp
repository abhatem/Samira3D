#include "Text2D.h"



void Text2D::init(Font *font, const std::string & text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color)
{
	m_font = font;
	m_text = text;
	m_x = x;
	m_y = y;
	m_scale = scale;
	m_color = color;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


Text2D::~Text2D()
{
}

void Text2D::draw(const Shader &sh)
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glDisable(GL_DEPTH_TEST);
	sh.use();
	//glUniform3f(glGetUniformLocation(sh.Program, "textColor"), color.x, color.y, color.z);
	sh.updateUniformVec3("textColor", m_color);
	sh.updateUniformMat4("projection", projection);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(VAO);
	float x_org = m_x, y_org = m_y;
	// Iterate through all characters
	std::string::const_iterator c;
	for (c = m_text.begin(); c != m_text.end(); c++)
	{
		Character ch = m_font->characters[*c];

		GLfloat xpos = m_x + ch.bearing.x * m_scale;
		GLfloat ypos = m_y - (ch.size.y - ch.bearing.y) * m_scale;

		GLfloat w = ch.size.x * m_scale;
		GLfloat h = ch.size.y * m_scale;
		// Update VBO for each character
		GLfloat vertices[6][4] = {
		{ xpos,     ypos + h,   0.0, 0.0 },
		{ xpos,     ypos,       0.0, 1.0 },
		{ xpos + w, ypos,       1.0, 1.0 },


		{ xpos,     ypos + h,   0.0, 0.0 },
		{ xpos + w, ypos,       1.0, 1.0 },
		{ xpos + w, ypos + h,   1.0, 0.0 }
		};
		// Render glyph texture over quad
		glBindTexture(GL_TEXTURE_2D, ch.textureID);
		// Update content of VBO memory
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// Render quad
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		m_x += (ch.advance >> 6) * m_scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
	}
	m_x = x_org;
	m_y = y_org;
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	//glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_ONE, GL_ZERO);
}

void Text2D::setText(const std::string & text)
{
	m_text = text;
}
