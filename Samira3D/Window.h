#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
namespace SE
{
	namespace Window
	{
		extern void init();
		extern void createWindow();
		extern GLFWwindow* getWindowHandle();
		extern bool shouldClose();
		extern void update();
		extern void render();
		extern void dispose();
	}
}