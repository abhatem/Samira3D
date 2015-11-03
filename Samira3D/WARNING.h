#pragma once

#include <string>

namespace S3D {

	class WARNING
	{
	public:
		WARNING(int warningCode, std::string str);
		~WARNING();
	};

}
