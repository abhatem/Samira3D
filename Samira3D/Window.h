#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <string>
namespace S3D
{
	namespace Window
	{
		extern void init(int width, int height, std::string title);
		extern void createWindow();
		extern GLFWwindow* getWindowHandle();
		extern bool shouldClose();
		extern void update();
		extern void render();
		extern void dispose();
		extern int getWidth();
		extern int getHeight();
		extern std::string getTitle();
		extern void setWidth(int width);
		extern void setHeight(int height);
		extern void setTitle(std::string title);
	}
}

