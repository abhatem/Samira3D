#pragma once

#include <boost\signals2.hpp>

#include <GLFW\glfw3.h>

namespace S3D
{
	namespace  Input
	{
		extern void init(GLFWwindow* window);
		//extern void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		extern boost::signals2::signal<void(int)> pressed;
		extern boost::signals2::signal<void(int)> released;
		extern boost::signals2::signal<void(int)> repeat;
	}

}

