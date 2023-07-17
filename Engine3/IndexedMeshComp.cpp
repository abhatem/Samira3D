#include "IndexedMeshComp.h"

void IndexedMeshComp::init(SceneObject * obj)
{
}

void IndexedMeshComp::update(SceneObject * obj)
{
}

void IndexedMeshComp::render(SceneObject * obj, CameraAbstract *cam, bool lightRender)
{
	mesh->draw();
}

void IndexedMeshComp::release(SceneObject * obj)
{
}
