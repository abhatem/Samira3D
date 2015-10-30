#include "Input.h"

#include <boost\signals2.hpp>
#include <GLFW\glfw3.h>

namespace SE 
{
	namespace Input
	{
		namespace
		{
			void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
					pressed(key);
					break;
				case GLFW_RELEASE:
					released(key);
					break;
				case GLFW_REPEAT:
					repeat(key);
					break;
				default:
					break;
				}
			}
		}
		boost::signals2::signal<void(int)> pressed;
		boost::signals2::signal<void(int)> released;
		boost::signals2::signal<void(int)> repeat;


		void init(GLFWwindow* window)
		{
			glfwSetKeyCallback(window, key_callback);
		}

		
	}
	
}