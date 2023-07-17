#include "MeshComp.h"

void MeshComp::init(SceneObject * obj)
{
}

void MeshComp::update(SceneObject * obj)
{
}

void MeshComp::render(SceneObject * obj, CameraAbstract *cam, bool lightRender)
{
	mesh->draw();
}

void MeshComp::release(SceneObject * obj)
{
}
