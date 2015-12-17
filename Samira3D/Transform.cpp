#include "Transform.h"
#include "Cameras.h"

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

glm::mat4 Transform::getTransformationMatrix()
{
	/*glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;*/
		/*
		glm::mat4(1.0f,1.0f,1.0f,1.0f,
										1.0f,1.0f,1.0f,1.0f,
										1.0f,1.0f,1.0f,1.0f
										1.0f,1.0f,1.0f,1.0f);*/
	/*float xRotation = m_rotation.x ;
	float yRotation = m_rotation.y;
	float zRotation = m_rotation.z;*/
	m_translationMatrix = glm::translate(m_translation);

	/*
	rotationMatrix = glm::rotate(m_rotation.x*glm::pi<float>()*2, glm::vec3(1, 0, 0));
	rotationMatrix *= glm::rotate(m_rotation.y*glm::pi<float>()*2, glm::vec3(0, 1, 0));
	rotationMatrix *= glm::rotate(m_rotation.z*glm::pi<float>()*2, glm::vec3(0, 0, 1));
	*/
	//glm::rotate()
	//rotationMatrix = glm::rotate(m_2pi, glm::vec3(1, 0, 0));
	//rotationMatrix *= glm::rotate(m_2pi, glm::vec3(0, 1, 0));
	//rotationMatrix *= glm::rotate(m_2pi, glm::vec3(0, 0, 1));
	/*
	rotationMatrix = glm::rotate(rotationMatrix, m_rotation.x, glm::vec3(10*m_pi, 0, 0));
	rotationMatrix = glm::rotate(rotationMatrix, m_rotation.y, glm::vec3(0, 10 * m_pi, 0));
	rotationMatrix = glm::rotate(rotationMatrix, m_rotation.z, glm::vec3(0, 0, 10 * m_pi));
	*/

	m_scaleMatrix = glm::scale(m_scale);
	

	return m_translationMatrix * m_rotationMatrix * m_scaleMatrix;
}

/*
glm::mat4 Transform::getTranslationMatrix()
{
	//glm::mat4 translationMatrix;
	return glm::translate(m_translation);
}


glm::mat4 Transform::getRotationMatrix()
{
	glm::mat4 rotationMatrix;
	rotationMatrix = glm::rotate(m_rotation.x*glm::pi<float>() * 2, glm::vec3(1, 0, 0));
	rotationMatrix *= glm::rotate(m_rotation.y*glm::pi<float>() * 2, glm::vec3(0, 1, 0));
	rotationMatrix *= glm::rotate(m_rotation.z*glm::pi<float>() * 2, glm::vec3(0, 0, 1));
	return rotationMatrix;
}
glm::mat4 Transform::getScalingMatrix()
{
	return glm::scale(m_scale);
	//glm::rotate()
}
*/

glm::mat4 Transform::getProjectedTransformation()
{
	//glm::mat4 transformationMatrix = getTransformationMatrix();
	glm::mat4 projectionMatrix = getProjectionMatrix() * Cameras::Cam[Cameras::Cam.size()-1].getCamMatrix() * getTransformationMatrix();
	return projectionMatrix;
}


glm::mat4 Transform::getProjectionMatrix()
{
	return glm::perspective(m_fieldOfView, m_width / m_height, m_zNear, m_zFar);
}
void Transform::setProjection(float fov, float width, float height, float zNear, float zFar)
{
	m_fieldOfView = fov;
	m_width = width;
	m_height = height;
	m_zNear = zNear;
	m_zFar = zFar;
}

void Transform::setRotation(const float &angle, const glm::vec3 &axis)
{
	m_rotationMatrix = glm::rotate(glm::mat4(1), angle*m_2pi, axis);
}