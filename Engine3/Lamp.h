#pragma once
#include "GeometricMesh.h"
#include "Transform.h"
#include "Shader.h"
#include "RenderPass.h"
#include "SceneObject.h"
#include "OrthoCamera.h"
#include "PerspectiveCamera.h"
class Lamp {
public:
	Lamp();
	
	/*void setTransform(const Transform &tr) { m_transform = tr; }
	Transform getTransform() const { return m_transform; }*/
	Transform transform;
	void setColor(const Vec3 &color) { m_color = color; }
	Vec3 getColor() { return m_color; }

	
	void draw();
	void renderDepthMap(SceneObject &root);
	void bindDepthMap();
	glm::mat4 getLightSpaceView() { return ocam.view(); }
	glm::mat4 getLightSpaceProjection() { return ocam.projection(); }
private:
	//RenderPass m_rp;
	Vec3 m_color;
	GeometricMesh m_mesh;
	OrthoCamera ocam;
};
