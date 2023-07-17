#pragma once
#include "glm/vec3.hpp"

enum LightType
{
	Directional = 1,
	Point = 2,
	Spot = 3
};
struct LightData {

		glm::vec3     diffuse;
		glm::vec3 specular;
		glm::vec3 ambient;
		glm::vec3 direction;
		glm::vec3 position;

		float constant;
		float linear;
		float quadratic;
	

		float cuttoff;

		LightType type;
};
//
//class Light {
//public:
//
//	glm::vec3 getDiffuse() const { return m_diffuse; }
//	glm::vec3 getSpecular() const { return m_specular; }
//	glm::vec3 getAmbient() const { return m_ambient; }
//	glm::vec3 getDirection() const { return m_direction; }
//	float getConstantMultiplier() const { return m_constant; }
//	float getLinearMultiplier() const { return m_linear; }
//	float getQuadraticMultiplier() const { return m_quadratic; }
//	float getCuttOff() const { return m_cuttoff; }
//
//	void setDiffuse(glm::vec3 diffuse) { m_diffuse = diffuse; }
//	void setSpecular(glm::vec3 specular) { m_specular = specular; }
//	void setAmbient(glm::vec3 ambient) { m_ambient = ambient; }
//	void setDirection(glm::vec3 direction) { m_direction = direction; }
//	void setConstantMultiplier(float constant) { m_constant = constant; }
//	void setLinearMultiplier(float linear) { m_linear = linear; }
//	void setQuadraticMultiplier(float quadratic) { m_quadratic = quadratic; }
//	void setCuttOff(float cuttoff) { m_cuttoff = cuttoff; }
//
//
//
//private:
//	// for all types
//	glm::vec3 m_diffuse;
//	glm::vec3 m_specular;
//	glm::vec3 m_ambient;
//	glm::vec3 m_direction;
//
//	// for point lights
//	float m_constant;
//	float m_linear;
//	float m_quadratic;
//
//	// for spot lights
//	float m_cuttoff;
//};
