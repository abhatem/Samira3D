#include "ERROR.h"
#include <iostream>

using namespace SE;

ERROR::ERROR(int errorCode, std::string str)
{
	std::cerr << "ERROR #" << errorCode << ": " << str << std::endl;
	exit(errorCode);
}


ERROR::~ERROR()
{
}
