#include <GL\glew.h>
#include "RenderUtil.h"

namespace S3D
{
	namespace RenderUtil
	{
		void clearScreen()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		}

		void initGraphics()
		{
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

			glFrontFace(GL_CW);
			glCullFace(GL_BACK);
			glEnable(GL_CULL_FACE);
			glEnable(GL_DEPTH_TEST);

			// TODO: depth clamp

			glEnable(GL_FRAMEBUFFER_SRGB); // to get free gamma correction
		}

		std::string getOpenGLVersion()
		{
			char *c = (char *)glGetString(GL_VERSION);
			//std::string *s = glGetString(GL_VERSION);
			return std::string(c);
		}
	}
}