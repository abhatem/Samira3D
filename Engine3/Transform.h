#pragma once


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

typedef glm::mat4 Mat4;
typedef glm::vec3 Vec3;
typedef glm::quat Quat;

#define VECTOR_UP Vec3( 0, 1, 0 )
#define VECTOR_DOWN Vec3( 0, -1, 0 )
#define VECTOR_RIGHT Vec3( 1, 0, 0 )
#define VECTOR_LEFT Vec3( -1, 0, 0 )
#define VECTOR_BACK Vec3( 0, 0, 1 )
#define VECTOR_FRONT Vec3( 0, 0, -1 )

class Transform
{
public:
	Transform();
	Transform(const Transform &other);
	~Transform();

	// Mat4 getTransformationMatrix();

	glm::mat4 getMatrix() const
	{
		return m_matrix;
	}


	Vec3 getTranslation() const
	{
		return m_translation;
	}
	void setTranslation(const Vec3 &translation)
	{
		m_translation = translation;
	}
	void setTranslation(float x, float y, float z)
	{
		m_translation = Vec3(x, y, z);
	}
	void move(const Vec3 &in);

	Quat getRotation() const
	{
		return m_rotation;
	}

	Mat4 getRotationMatrix() const
	{
		return glm::toMat4(m_rotation);
	}


	void setRotation(float angle, const Vec3 &axis);
	void setRotation(glm::quat rotation)
	{
		m_rotation = rotation;
		calcMatrix();
	}

	void setRotation(Mat4 rotationMatrix);

	void rotate(float angle, const Vec3 &axis);
	void rotate(Quat rotation);

	Vec3 getScale() const
	{
		return m_scale;
	}
	void setScale(const Vec3 &scale)
	{
		m_scale = scale;
	}
	void setScale(float x, float y, float z)
	{
		m_scale = Vec3(x, y, z);
		calcMatrix();

	}
	void scale(const Vec3 &scale)
	{
		m_scale += scale;
		calcMatrix();
	}


	Vec3 getForward() const
	{
		return m_forward;
	}
	Vec3 getRight() const
	{
		return m_right;
	}
	Vec3 getUp() const
	{
		return m_up;
	}

	static Quat matToQuat(Mat4 mat)
	{
		return glm::quat_cast(mat);
	}


	void lookAt(Vec3 target)
	{
		setRotation(glm::lookAt(m_translation, target, VECTOR_UP));
		calcMatrix();
	}


	Mat4 getTranslationMatrix() const { return m_translationMatrix; }



	void calcMatrix();




	// glm::mat4 getProjectionMatrix();

private:
	Vec3 m_translation;
	Quat m_rotation;
	Vec3 m_scale;

	Mat4 m_translationMatrix;
	Mat4 m_rotationMatrix;
	Mat4 m_scaleMatrix;

	Vec3 m_forward;
	Vec3 m_right;
	Vec3 m_up;

	Mat4 m_matrix;
};




