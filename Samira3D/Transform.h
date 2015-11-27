#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace S3D
{
	class Transform
	{
	public:
		Transform();
		~Transform();

		glm::mat4 getTransformation();

		glm::mat4 getProjectedTransformation();

		void setProjection(float fov, float width, float height, float zNear, float zFar);

		glm::vec3 getTranslation() { return m_translation; }
		void setTranslation(glm::vec3 translation) { m_translation = translation; }
		void setTranslation(float x, float y, float z) { m_translation = glm::vec3(x, y, z); }

		glm::vec3 getRotation() { return m_rotation; }
		void setRotation(glm::vec3 rotation) { m_rotation = rotation; }
		void setRotation(float x, float y, float z) { m_rotation = glm::vec3(x, y, z); }

		glm::vec3 getScale() { return m_scale; }
		void setScale(glm::vec3 scale) { m_scale = scale; }
		void setScale(float x, float y, float z) { m_scale = glm::vec3(x, y, z); }

	private:
		glm::vec3 m_translation;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;

		float m_zNear;
		float m_zFar;
		float m_width;
		float m_height;

		float m_fieldOfView;
	};
}

