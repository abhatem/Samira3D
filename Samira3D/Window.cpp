#include "Window.h"
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

namespace SE
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
				exit(1);

			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		}

		void createWindow()
		{
			m_window = glfwCreateWindow(800, 600, "My Title", NULL, NULL);
			if (!m_window)
			{
				glfwTerminate();
				exit(EXIT_FAILURE);
			}
			
			glfwMakeContextCurrent(m_window); // Initialize GLEW 
			glewExperimental = true; // Needed in core profile 
			if (glewInit() != GLEW_OK) {
				fprintf(stderr, "Failed to initialize GLEW\n");
				exit(1);
			}
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