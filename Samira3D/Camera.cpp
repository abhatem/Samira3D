#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
using namespace S3D;

Camera::Camera(glm::vec3 pos, glm::vec3 m_lookAtPos, glm::vec3 up)
{
	m_pos = pos;
	m_lookAtPos = m_lookAtPos;
	m_up = up;

	//m_up = glm::normalize(m_up);
	//m_forward = glm::normalize(m_forward);
}


glm::mat4 Camera::getCamMatrix()
{
	return glm::lookAt(
		m_pos,
		m_lookAtPos,
		m_up
	);
}

Camera::Camera() : 
	Camera(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0))
{
	
}

void Camera::move(glm::vec3 dir, glm::vec3 amt)
{
	m_pos = m_pos + (dir * amt);
}

//
//glm::vec3 Camera::getLeft()
//{
//	glm::vec3 left = glm::cross(m_up, m_forward);
//	left = glm::normalize(left);
//	return left;
//}
//
//glm::vec3 Camera::getRight()
//{
//	glm::vec3 right = glm::cross(m_forward, m_up);
//	right = glm::normalize(right);
//	return right;
//}
//
//void Camera::rotateX(float angle)
//{
//	glm::vec3 Haxis = glm::cross(yAxis, m_forward);
//	Haxis = glm::normalize(Haxis);
//
//	m_forward = glm::rotate(m_forward, angle, Haxis);
//	m_forward = glm::normalize(m_forward);
//
//	m_up = glm::cross(m_forward, Haxis);
//	m_up = glm::normalize(m_up);
//}
//
//void Camera::rotateY(float angle)
//{
//	glm::vec3 Haxis = glm::cross(yAxis, m_forward);
//	Haxis = glm::normalize(Haxis);
//
//	m_forward = glm::rotate(m_forward, angle, yAxis);
//	m_forward = glm::normalize(m_forward);
//
//	m_up = glm::cross(m_forward, Haxis);
//	m_up = glm::normalize(m_up);
//}

Camera::~Camera()
{
}
