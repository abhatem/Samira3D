#pragma once
#include <glm/glm.hpp>
#include "Transform.h"
class CameraAbstract {
public:
	virtual glm::mat4 projection() = 0;
	virtual glm::mat4 view() = 0;
	virtual glm::mat4 matrix() = 0;
	virtual Transform getTransform() = 0;
};