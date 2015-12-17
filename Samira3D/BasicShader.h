#pragma once
#include "Shader.h"
namespace S3D {
	class BasicShader :
		public S3D::Shader
	{
	public:
		BasicShader();
		~BasicShader();

		void updateUniforms(const glm::mat4 &worldMatrix, const glm::mat4 &projectedMatrix, Material *material);
		// for testing purposes
		void updateUniforms(const glm::mat4 &worldMatrix, const glm::mat4 &projectedMatrix);
	};
}

