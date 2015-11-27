#pragma once

namespace S3D {
	class Texture
	{
	public:
		Texture(int id);
		~Texture();

		void bind();

		unsigned int getId() { return m_id; }


	private:
		unsigned int m_id;
	};
}
