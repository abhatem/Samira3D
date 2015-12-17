#include "Shaders.h"


namespace S3D
{
	namespace Shaders
	{
		boost::shared_ptr<BasicShader> basicShader;
		boost::shared_ptr<PhongShader> phongShader;
		void init()
		{
			basicShader = boost::shared_ptr<BasicShader>(new BasicShader);
			phongShader = boost::shared_ptr<PhongShader>(new PhongShader);
		}

	}
}
