#pragma once

#include "Component.h"
#include "Mesh.h"
class MeshComp : public Component {
	// Inherited via Component
public:
	virtual void init(SceneObject * obj) override;
	virtual void update(SceneObject * obj) override;
	virtual void render(SceneObject * obj, CameraAbstract *cam, bool lightRender = 0) override;
	virtual void release(SceneObject * obj) override;
	Mesh *mesh;
	
};
