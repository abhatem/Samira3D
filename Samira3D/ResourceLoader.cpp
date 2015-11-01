#include <iostream>

#include "ResourceLoader.h"

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
	}
}