#pragma once
#include <string>
namespace S3D 
{
	namespace RenderUtil
	{
		extern void clearScreen(); // should be called before rendering to clear the screen from previous render
		extern void initGraphics(); // contains opengl calls that initialize the library
		extern std::string getOpenGLVersion(); // gets the opengl version that this computer is running
		extern void setTexturesEnabled(bool enabled);
	}

}