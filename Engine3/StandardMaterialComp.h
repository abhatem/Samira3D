#pragma once
#include "Component.h"
#include "Texture.h"
#include "Shader.h"
#include "Lamp.h"
#include "DirectionalLight.h"
class StandardMaterialComp : public Component {
public:
	StandardMaterialComp() {}
	virtual void init(SceneObject * obj) override;
	virtual void update(SceneObject * obj) override;
	virtual void render(SceneObject * obj, CameraAbstract *cam, bool lightRender = false) override;
	virtual void release(SceneObject * obj) override;
	Shader *shader;
	Shader *lightDepthShader;
	Texture *diffuseTexture;
	Texture *specularTexture;
	Texture *normalTexture;
	DirectionalLight directionalLights;
	Lamp *lamp;
};