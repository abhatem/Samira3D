#pragma once


#include <string>
#include "CameraAbstract.h"
// #include "SceneObject.h"

class SceneObject;

class Component
{
public:
	

	virtual void init(SceneObject *obj) = 0;
	virtual void update(SceneObject *obj) = 0;
	virtual void render(SceneObject *obj, CameraAbstract *cam, bool lightRender = 0) = 0;
	virtual void release(SceneObject *obj) = 0;

	


protected:


private:

};






