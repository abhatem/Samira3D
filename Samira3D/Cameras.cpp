#include "Cameras.h"


namespace S3D
{
	namespace Cameras
	{
		std::vector<Camera> Cam;

		void addCamera(Camera cam)
		{
			Cam.push_back(cam);
		}
	}
}
