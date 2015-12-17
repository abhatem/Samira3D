#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace S3D
{
	class Transform
	{
	public:
		Transform();
		~Transform();

		glm::mat4 getTransformationMatrix();

		glm::mat4 getProjectedTransformation();

		void setProjection(float fov, float width, float height, float zNear, float zFar);

		glm::vec3 getTranslation() { return m_translation; }
		void setTranslation(const glm::vec3 &translation) { m_translation = translation; }
		void setTranslation(float x, float y, float z) { m_translation = glm::vec3(x, y, z); }

		glm::vec3 getRotation() { return m_rotation; }
		//void setRotation(const glm::vec3 &rotation);// { m_rotation = rotation; }
		//void setRotation(float x, float y, float z) { m_rotation = glm::vec3(x, y, z); }

		void setRotation(const float &angle, const glm::vec3 &axis);

		glm::vec3 getScale() { return m_scale; }
		void setScale(const glm::vec3 &scale) { m_scale = scale; }
		void setScale(float x, float y, float z) { m_scale = glm::vec3(x, y, z); }
		/*
		glm::mat4 getTranslationMatrix();
		glm::mat4 getRotationMatrix();
		glm::mat4 getScalingMatrix();
		*/

		glm::mat4 getProjectionMatrix();

	private:
		glm::vec3 m_translation;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;

		glm::mat4 m_translationMatrix;
		glm::mat4 m_rotationMatrix;
		glm::mat4 m_scaleMatrix;

		float m_zNear;
		float m_zFar;
		float m_width;
		float m_height;

		float m_fieldOfView;

		//float pi = 3.14159265;
		float m_pi = glm::pi<float>();
		float m_2pi = m_pi * 2;
	};
}

