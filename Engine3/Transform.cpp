#pragma once
#include "Transform.h"

#include <glm/gtx/quaternion.hpp>



Transform::Transform()
{
	m_translation = glm::vec3(0.0, 0.0, 0.0);
	m_rotation = glm::quat(glm::radians(0.0f), glm::vec3(0, 0, 0));
	m_scale = glm::vec3(1.0, 1.0, 1.0);

	calcMatrix();

}

Transform::Transform(const Transform &other)
{
	m_translation = other.getTranslation();
	m_rotation = other.getRotation();
	m_scale = other.getScale();
	calcMatrix();
}

Transform::~Transform()
{
}

// glm::mat4 Transform::getTransformationMatrix()
// {
//     m_translationMatrix = glm::translate( m_translation );

//     m_rotationMatrix = glm::toMat4( m_rotation );
//     m_scaleMatrix = glm::scale( m_scale );

//     return m_translationMatrix * m_rotationMatrix * m_scaleMatrix;
// }

void Transform::move(const glm::vec3 &in)
{
	m_translation += in;
	calcMatrix();
}

void Transform::setRotation(float angle, const Vec3 &axis)
{
	m_rotation = glm::angleAxis(angle, axis);
	calcMatrix();

}

void Transform::rotate(float angle, const Vec3 &axis)
{

	m_rotation *= glm::angleAxis(angle, axis);
	m_rotation = glm::normalize(m_rotation);

	calcMatrix();

}

void Transform::rotate(Quat rotation)
{
	// NOT TESTED
	m_rotation *= rotation;
	m_rotation = glm::normalize(m_rotation);

	calcMatrix();

}

//TODO: check if this could run on another thread.
void Transform::calcMatrix()
{
	m_translationMatrix = glm::translate(m_translation);

	m_rotationMatrix = glm::mat4_cast(m_rotation);

	m_scaleMatrix = glm::scale(m_scale);

	m_matrix = m_translationMatrix * m_rotationMatrix * m_scaleMatrix;

	m_forward = Vec3(
		2.0f * (m_rotation.x * m_rotation.z - m_rotation.w * m_rotation.y),
		2.0f * (m_rotation.y * m_rotation.z + m_rotation.w * m_rotation.x),
		1.0f - 2.0f * (m_rotation.x * m_rotation.x + m_rotation.y * m_rotation.y)
	);

	m_up = Vec3(
		2.0f * (m_rotation.x * m_rotation.y + m_rotation.w * m_rotation.z),
		1.0f - 2.0f * (m_rotation.x * m_rotation.x + m_rotation.z * m_rotation.z),
		2.0f * (m_rotation.y * m_rotation.z - m_rotation.w * m_rotation.x)
	);

	m_right = glm::cross(m_up, m_forward);


}



void Transform::setRotation(Mat4 rotationMatrix)
{
	m_rotation = matToQuat(rotationMatrix);

	calcMatrix();
}
