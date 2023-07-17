#pragma once

#pragma once

#include "Component.h"
#include "Shader.h"
#include "Texture.h"
#include "CameraAbstract.h"
#include "Lamp.h"
class MaterialNormalComp : public Component {
	// Inherited via Component
public:
	MaterialNormalComp() {}
	virtual void init(SceneObject * obj) override;
	virtual void update(SceneObject * obj) override;
	virtual void render(SceneObject * obj, CameraAbstract *cam, bool lightRender = false) override;
	virtual void release(SceneObject * obj) override;
	Shader *shader;
	Shader *lightDepthShader;
	Texture *diffuseTexture;
	//Texture specularTexture;
	Texture *normalTexture;
	Lamp *lamp;
};