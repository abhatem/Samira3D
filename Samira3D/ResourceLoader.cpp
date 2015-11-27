#include <iostream>

#include "ResourceLoader.h"
#include <GL\glew.h>
#include "SOIL\SOIL.h"
#include "WARNING.h"


namespace S3D
{
	namespace ResourceLoader
	{
		std::string loadTextFile(std::string fileName)
		{
			std::string Text;
			std::ifstream Stream(fileName, std::ios::in);
			if (Stream.is_open())
			{
				std::string Line = "";
				while (std::getline(Stream, Line))
					Text += "\n" + Line;
				Stream.close();
			}

			return Text;
		}

		Texture loadTexture(std::string filename)
		{
			Texture t = Texture(SOIL_load_OGL_texture("test.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
				SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
				));

			if (t.getId() == 0)
			{
				WARNING(2, "Can't load texture: " + filename);
			}

			return t;
		}
	}
}