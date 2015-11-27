#include "Transform.h"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace S3D;

Transform::Transform()
{
	m_translation = glm::vec3(0.0, 0.0, 0.0);
	m_rotation = glm::vec3(0.0, 0.0, 0.0);
	m_scale = glm::vec3(1.0, 1.0, 1.0);
}


Transform::~Transform()
{
}

glm::mat4 Transform::getTransformation()
{
	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;
		/*
		glm::mat4(1.0f,1.0f,1.0f,1.0f,
										1.0f,1.0f,1.0f,1.0f,
										1.0f,1.0f,1.0f,1.0f
										1.0f,1.0f,1.0f,1.0f);*/
	/*float xRotation = m_rotation.x ;
	float yRotation = m_rotation.y;
	float zRotation = m_rotation.z;*/
	translationMatrix *= glm::translate(translationMatrix, m_translation);
	rotationMatrix = glm::rotate(m_rotation.x*glm::pi<float>()*2, glm::vec3(1, 0, 0));
	rotationMatrix *= glm::rotate(m_rotation.y*glm::pi<float>()*2, glm::vec3(0, 1, 0));
	rotationMatrix *= glm::rotate(m_rotation.z*glm::pi<float>()*2, glm::vec3(0, 0, 1));


	/*rotationMatrix = glm::rotate(rotationMatrix, m_rotation.x, glm::vec3(12.0f*(22.0f/7.0f), 0, 0));
	rotationMatrix *= glm::rotate(rotationMatrix, m_rotation.y, glm::vec3(0, 12.0f * (22.0f/7.0f), 0));
	rotationMatrix *= glm::rotate(rotationMatrix, m_rotation.z, glm::vec3(0, 0, 12.0f * (22.0f/7.0f)));

	*/

	scaleMatrix = glm::scale(m_scale);
	

	return translationMatrix * rotationMatrix * scaleMatrix;
}

glm::mat4 Transform::getProjectedTransformation()
{
	glm::mat4 transformationMatrix = getTransformation();
	glm::mat4 projectionMatrix = transformationMatrix * glm::perspective(m_fieldOfView, m_width / m_height, m_zNear, m_zFar);
	return projectionMatrix;
}

void Transform::setProjection(float fov, float width, float height, float zNear, float zFar)
{
	m_fieldOfView = fov;
	m_width = width;
	m_height = height;
	m_zNear = zNear;
	m_zFar = zFar;
}