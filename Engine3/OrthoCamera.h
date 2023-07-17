#pragma once
#pragma once



#include "Transform.h"
#include "CameraAbstract.h"
//glm::vec3 world_up = glm::vec3(0, 1, 0);

class OrthoCamera : public CameraAbstract
{
public:
	OrthoCamera();
	//Camera(RenderTarget *renderTexture);

	Transform getTransform()
	{
		return m_transform;
	}
	void setTransform(Transform transform)
	{
		m_transform = transform;
	}
	//void updateLook(float mouseX, float mouseY, float sensitivity);

	void rotate(float pitch, float yaw);

	void setProjection(float left, float top, float right, float bottom, float zNear, float zFar);

	void getMVP(Mat4 &M, Mat4 &V, Mat4 &P);
	void setTranslation(glm::vec3 translation)
	{
		m_transform.setTranslation(translation);
	}

	void move(const glm::vec3 &localTranslation);

	float getPitch() const;
	void setPitch(float pitch);

	float getYaw() const;
	void setYaw(float yaw);


	void lookAt(Vec3 target);


	glm::vec3 getForward();

	glm::vec3 getUp();

	glm::vec3 getRight();

	glm::mat4 view();

	glm::mat4 orientation();

	glm::mat4 projection();

	glm::mat4 matrix();

	void normalizeAngles();

	/*RenderTarget getRenderTexture() const
	{
	return *m_renderTexture;
	}
	void setRenderTexture(RenderTarget *renderTexture)
	{
	m_renderTexture = renderTexture;
	}*/

	//bool hasRenderTexture() const
	//{
	//	return m_renderTexture == NULL;
	//}


private:
	mutable Transform m_transform; // after implementing the game scene, this should be in the GameObject class and the camera should inherit it's properties from there.

	glm::vec3 m_lookAt;
	glm::vec3 m_up;
	glm::vec3 m_forward;
	glm::vec3 m_right;
	float m_zNear;
	float m_zFar;
	/*float m_aspect;
	float m_fieldOfView;*/
	float m_leftClip, m_topClip, m_rightClip, m_bottomClip;

	float m_last_mouseX;
	float m_last_mouseY;

	glm::vec3 world_up;
	glm::mat4 m_view;
	float m_pitch;
	float m_yaw;

	//RenderTarget *m_renderTexture;
};



