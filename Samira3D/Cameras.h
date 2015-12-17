#pragma once
#include "Camera.h"
#include <vector>
#include <boost\smart_ptr.hpp>
namespace S3D
{
	namespace Cameras
	{
		extern std::vector<Camera> Cam;
		extern void addCamera(Camera cam);
	}
}
