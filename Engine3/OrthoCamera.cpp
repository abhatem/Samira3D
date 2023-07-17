

#include "OrthoCamera.h"

#include <glm/gtc/quaternion.hpp>
#include <cmath>



OrthoCamera::OrthoCamera()
{
	//currentRotatioinAroundX = 0;
	world_up = glm::vec3(0, 1, 0);
	m_last_mouseX = 0;
	m_last_mouseY = 0;
	m_forward = glm::vec3(0, 0, 1);
	m_pitch = 0;
	m_yaw = 0;

}

//OrthoCamera::OrthoCamera(RenderTarget *renderTexture)
//{
//	m_renderTexture = renderTexture;
//}

void OrthoCamera::rotate(float pitch, float yaw)
{
	m_pitch += pitch;
	m_yaw += yaw;

	normalizeAngles();
}



void OrthoCamera::setProjection(float left, float top, float right, float bottom, float zNear, float zFar)
{
	
	m_leftClip = left; m_topClip = top; m_rightClip = right; m_bottomClip = bottom;
	m_zNear = zNear;
	m_zFar = zFar;
}


void OrthoCamera::move(const glm::vec3 &localTranslation)
{
	m_transform.move(localTranslation);
}

float OrthoCamera::getPitch() const
{
	return m_pitch;
}

void OrthoCamera::setPitch(float pitch)
{
	m_pitch = pitch;
	normalizeAngles();
	m_view = orientation() * glm::inverse(m_transform.getTranslationMatrix());

}

float OrthoCamera::getYaw() const
{
	return m_yaw;
}

void OrthoCamera::setYaw(float yaw)
{
	m_yaw = yaw;
	normalizeAngles();
	m_view = orientation() * glm::inverse(m_transform.getTranslationMatrix());

}

glm::vec3 OrthoCamera::getForward()
{
	glm::vec4 forward = glm::inverse(orientation()) * glm::vec4(0, 0, -1, 1);
	return glm::vec3(forward);
}

glm::vec3 OrthoCamera::getUp()
{
	glm::vec4 up = glm::inverse(orientation()) * glm::vec4(0, 1, 0, 1);
	return glm::vec3(up);
}

glm::vec3 OrthoCamera::getRight()
{
	glm::vec4 right = glm::inverse(orientation()) * glm::vec4(1, 0, 0, 1);
	return glm::vec3(right);
}


void OrthoCamera::lookAt(Vec3 target)
{
	m_view = glm::lookAt(m_transform.getTranslation(), target, glm::vec3(0.0f, 1.0f, 0.0f));
	/*Mat4 m = glm::lookAt(m_transform.getTranslation(), target, Vec3(0.0f, 1.0f, 0.0f));*/
	//glm::quat q = glm::conjugate(glm::toQuat(glm::transpose(m)));
	////glm::normalize(q);
	//Vec3 v = glm::eulerAngles(q);
	////m_pitch = v.y;
	//m_yaw = glm::degrees(v.z);
	//-----------------
	// assert(target != m_transform.getTranslation());

	// glm::vec3 direction = glm::normalize(target-m_transform.getTranslation());
	// float dot = glm::dot(glm::vec3(0, 0, 1), direction);
	// if (fabs(dot - (-1.0f)) < 0.000001f) {
	//     m_transform.setRotation(glm::angleAxis(glm::degrees(M_PI), glm::vec3(0, 1, 0)));
	//     return;
	// }
	// else if (fabs(dot - (1.0f)) < 0.000001f) {
	//     m_transform.setRotation( glm::quat());
	//     return;
	// }

	// float angle = -glm::degrees(acosf(dot));

	// glm::vec3 cross = glm::normalize(glm::cross(glm::vec3(0, 0, 1), direction));
	// m_transform.setRotation( glm::normalize(glm::angleAxis(angle,
	// cross)));

	// m_transform.setRotation(glm::lookAt(m_transform.getTranslation(), target, VECTOR_UP));
	// normalizeAngles();

}


glm::mat4 OrthoCamera::view()
{
	// return orientation() * glm::translate(glm::mat4(), -m_transform.getTranslation());
	return m_view;
	//return orientation() * glm::inverse(m_transform.getTranslationMatrix());


	// return glm::inverse(orientation()); // * glm::inverse(m_transform.getTranslationMatrix());


}

glm::mat4 OrthoCamera::orientation()
{
	// glm::mat4 orientation = glm::mat4(1);
	// orientation = glm::rotate(orientation, glm::radians(m_pitch), glm::vec3(1, 0, 0));
	// orientation = glm::rotate(orientation, glm::radians(m_yaw), glm::vec3(0, 1, 0));
	// return orientation;

	m_transform.setRotation(glm::radians(m_pitch), glm::vec3(1, 0, 0));
	m_transform.rotate(glm::radians(m_yaw), glm::vec3(0, 1, 0));
	return glm::toMat4(m_transform.getRotation());
}

glm::mat4 OrthoCamera::projection()
{
	return glm::ortho<float>(m_leftClip, m_rightClip, m_bottomClip, m_topClip, m_zNear, m_zFar);
}

glm::mat4 OrthoCamera::matrix()
{
	return projection() * view();
}



void OrthoCamera::normalizeAngles()
{
	m_yaw = fmodf(m_yaw, 360.0f);
	//fmodf can return negative values, but this will make them all positive
	if (m_yaw < 0.0f)
		m_yaw += 360.0f;


}
