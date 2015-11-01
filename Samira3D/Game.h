#pragma once
#include "Mesh.h"

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

};

