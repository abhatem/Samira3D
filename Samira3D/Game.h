#pragma once
#include "Mesh.h"
#include "Shader.h"

class Game
{
public:
	Game();
	~Game();

	void update();
	void render();
	void dispose();

private:
	S3D::Mesh mesh;
	S3D::Shader shader;
};

