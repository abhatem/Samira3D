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
			int m_width;
			int m_height;
			std::string m_title;
			int flags;
		}

		int getWidth()
		{
			return m_width;
		}

		int getHeight()
		{
			return m_height;
		}

		std::string getTitle()
		{
			return m_title;
		}

		void setWidth(int width)
		{
			m_width = width;
		}

		void setHeight(int height)
		{
			m_height = height;
		}

		void setTitle(std::string title)
		{
			m_title = title;
		}

		void init(int width, int height, std::string title)
		{

			m_width = width;
			m_height = height;
			m_title = title;
			if (!glfwInit())
				ERROR(1, "Faild to initialize GLFW.");

			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
			//glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing // lowers the frame rate a lot
			m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
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
			return (bool)glfwWindowShouldClose(m_window);
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