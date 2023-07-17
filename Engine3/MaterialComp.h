#pragma once

#include "Component.h"
#include "Shader.h"
#include "Texture.h"
#include "CameraAbstract.h"
#include "Lamp.h"
class MaterialComp : public Component {
	// Inherited via Component
public:
	MaterialComp() {}
	virtual void init(SceneObject * obj) override;
	virtual void update(SceneObject * obj) override;
	virtual void render(SceneObject * obj, CameraAbstract *cam, bool lightRender = false) override;
	virtual void release(SceneObject * obj) override;
	Shader *shader;
	Shader *lightDepthShader;
	Texture *diffuseTexture;
	Texture *specularTexture;
	Lamp *lamp;
};