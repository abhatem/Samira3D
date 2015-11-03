#include "Window.h"
#include <iostream>
#include "ERROR.h"
namespace S3D
{
	namespace Window
	{
		namespace
		{
			GLFWwindow *m_window;
		}

		void init()
		{
			if (!glfwInit())
				ERROR(1, "Faild to initialize GLFW.");

			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
			glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing // lowers the frame rate a lot
			m_window = glfwCreateWindow(1024, 768, "My Title", NULL, NULL);
			if (!m_window)
			{
				glfwTerminate();
				ERROR(2, "Faild to create GLFW window.");
			}

			glfwMakeContextCurrent(m_window); // Initialize GLEW 
			glewExperimental = true; // Needed in core profile 
			//ERROR(2, "YEAH!");
			if (glewInit() != GLEW_OK)
			{
				ERROR(1, "Faild to initialize GLEW.");
			}
			
		}

		void createWindow()
		{
			
		}

		GLFWwindow* getWindowHandle()
		{
			return m_window;
		}

		bool shouldClose()
		{
			return glfwWindowShouldClose(m_window);
		}

		void update()
		{
			glfwPollEvents();
		}

		void render()
		{
			glfwSwapBuffers(m_window);
		}

		void dispose()
		{
			glfwDestroyWindow(m_window);
			glfwTerminate();
		}
	}
}