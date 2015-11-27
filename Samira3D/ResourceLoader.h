#pragma once
#include <string>
#include <fstream>
#include "Texture.h"
namespace S3D
{
	namespace ResourceLoader
	{
		std::string loadTextFile(std::string fileName);
		Texture loadTexture(std::string filename);
		
	}
}
