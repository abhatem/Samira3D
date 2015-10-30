#include <GLFW\glfw3.h>

namespace SE 
{
	namespace Time
	{

		namespace {
			double m_delta;
		}

		double getTime() 
		{
			return glfwGetTime();
		}

		void setDelta(double delta)
		{
			m_delta = delta;
		}

		double getDelta()
		{
			return m_delta;
		}
	}
}