#include "ERROR.h"
#include <iostream>

using namespace S3D;

ERROR::ERROR(int errorCode, std::string str)
{
	std::cerr << "ERROR #" << errorCode << ": " << str << std::endl;
	system("PAUSE");
	exit(errorCode);
}


ERROR::~ERROR()
{
}
