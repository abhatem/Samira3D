#pragma once

#include "Texture.h"
#include <glm/vec3.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

namespace S3D {
	typedef boost::shared_ptr<Texture> TEXTURE;
	
	class Material
	{
	public:
		Material(TEXTURE texture, glm::vec3 color);
		~Material();

		TEXTURE getTexture() { return m_texture; }
		glm::vec3 getColor() { return m_color; }

		void setTexture(TEXTURE texture) { m_texture = texture; }
		void setColor(glm::vec3 color) { m_color = color; }

	private:
		TEXTURE m_texture;
		glm::vec3 m_color;
	};

}
