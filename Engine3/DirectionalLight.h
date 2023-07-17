#pragma once
#include "GeometricMesh.h"
#include "Transform.h"
#include "Shader.h"
#include "RenderPass.h"
#include "SceneObject.h"
#include "OrthoCamera.h"
#include "PerspectiveCamera.h"
#include "LightData.h"
#include "Transform.h"
class DirectionalLight {
public:
	DirectionalLight();
	//Transform transform;
	//void setColor(const Vec3 color) { m_color = color; }
	//Vec3 getColor() { return m_color; }

	void            draw();                 //TODO: render light mesh.
	void            renderDepthMap(SceneObject &root, const glm::vec3 &lookAt);
	void            bindDepthMap();
	glm::mat4       getLightSpaceView()        { return ocam.view(); }
	glm::mat4       getLightSpaceProjection()  { return ocam.projection(); }
	
private:
	//GeometricMesh m_mesh;
	OrthoCamera ocam;

};

