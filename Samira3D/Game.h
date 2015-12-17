#pragma once
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "Texture.h"
#include "SceneLoader.h"
#include "Camera.h"
#include "Material.h"


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
	//S3D::Shader shader;
	S3D::Transform transform;
	//S3D::Texture *texture;
	S3D::Material *material;
	//S3D::Material mat;
	S3D::SceneLoader *sl;
	//S3D::Camera *cam;



	void keyRepeat(int key);
};

