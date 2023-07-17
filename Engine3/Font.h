#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H  
#include <map>
#include <string>

struct Character {
	GLuint     textureID;  // ID handle of the glyph texture
	glm::ivec2 size;       // Size of glyph
	glm::ivec2 bearing;    // Offset from baseline to left/top of glyph
	GLuint     advance;    // Offset to advance to next glyph
};


class Font
{
public:
	Font() {}
	void init(const std::string &name, int size);
	~Font();
	std::map<GLchar, Character> characters;
};

