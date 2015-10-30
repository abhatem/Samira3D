#pragma once
#include <string>
namespace SE{
	class ERROR
	{
	public:
		ERROR(int errorCode, std::string str);
		~ERROR();
	};
}

