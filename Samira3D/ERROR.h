#pragma once
#include <string>
namespace S3D{
	class ERROR
	{
	public:
		ERROR(int errorCode, std::string str);
		~ERROR();
	};
}

