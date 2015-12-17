#pragma once
#include "BasicShader.h"
#include "PhongShader.h"
#include <boost\smart_ptr\shared_ptr.hpp>
namespace S3D
{
	namespace Shaders
	{
		extern void init();
		//extern void dispose();
		
		extern boost::shared_ptr<BasicShader> basicShader;
		extern boost::shared_ptr<PhongShader> phongShader;
	}
}
