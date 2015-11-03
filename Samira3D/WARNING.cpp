#include "WARNING.h"

#include <iostream>

using namespace S3D;

WARNING::WARNING(int warningCode, std::string str)
{
	std::cerr << "WARNING #" << warningCode << ": " << str << std::endl;
}


WARNING::~WARNING()
{
}
