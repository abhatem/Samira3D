#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#define yAxis glm::vec3(0, 1, 0)

namespace S3D {

	class Camera
	{
	public:
		Camera(glm::vec3 pos, glm::vec3 lookAtPos, glm::vec3 up);
		Camera();
		~Camera();

		glm::vec3 getPosition() { return m_pos; }
		glm::vec3 getUp() { return m_up; }
		glm::vec3 getLookAtPos() { return m_lookAtPos; }

		//glm::vec3 getLeft();

		//glm::vec3 getRight();

		//void rotateX(float angle);

		glm::mat4 getCamMatrix();

	/*	void rotateY(float angle);*/

		void move(glm::vec3 dir, glm::vec3 up);

		void setPosition(glm::vec3 pos) { m_pos = pos; }
		void setUp(glm::vec3 up) { m_up = up; }
		void setLookAtPos(glm::vec3 lookAtPos) { m_lookAtPos = lookAtPos; }

		void setPosition(float x, float y, float z) { m_pos = glm::vec3(x, y, z); }
		void setUp(float x, float y, float z) { m_up = glm::vec3(x, y, z); }
		void setLookAtPos(float x, float y, float z) { m_lookAtPos = glm::vec3(x, y, z); }

		void lookAt(float x, float y, float z) { setLookAtPos(x, y, z); }
		void lookAt(glm::vec3 lookAtPos) { setLookAtPos(lookAtPos); }

	private:
		glm::vec3 m_pos;
		glm::vec3 m_up;
		glm::vec3 m_lookAtPos;
		//glm::vec3 m_forward;
	};

}

