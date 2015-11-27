#include "Game.h"
#include "Input.h"
#include "Vertex.h"
#include "Time.h"
#include "ResourceLoader.h"
#include <iostream>
#include <glm/vec3.hpp>
#include <glm/gtc/constants.hpp>
//#include "SceneLoader.h"
using namespace S3D;

void keyPresed(int key)
{
	std::cout << "key " << char(key) << " pressed!" << std::endl;
}

Game::Game()
{
	S3D::Input::pressed.connect(keyPresed);
	std::vector<Vertex> v;
	std::vector<unsigned int> ind;
	v.push_back(Vertex(glm::vec3(-1, -1, 0), glm::vec2(0.0f, 0.0f)));	
	v.push_back(Vertex(glm::vec3(0, -1, 1), glm::vec2(0.5f, 0.0f)));
	v.push_back(Vertex(glm::vec3(0, 1, 0), glm::vec2(1.0f, 0.0f)));
	v.push_back(Vertex(glm::vec3(1, -1, 0), glm::vec2(0.0f, 0.5f)));
	
	
	ind.push_back(0);
	ind.push_back(3);
	ind.push_back(1);
	ind.push_back(1);
	ind.push_back(3);
	ind.push_back(2);
	ind.push_back(2);
	ind.push_back(3);
	ind.push_back(0);
	ind.push_back(0);
	ind.push_back(1);
	ind.push_back(2);
	ind.push_back(0);
	ind.push_back(1);
	ind.push_back(2);
	unsigned int *k = &ind.front();
	
	//transform.setProjection(70, )

	mesh.addVertices(v, ind);
	
	texture = new Texture(ResourceLoader::loadTexture("test.png"));
	
	//sl = new SceneLoader("Samira.obj");
	//transform.setProjection(60, 1024, 768, 0.01, 500);
	shader.addVertexShader(ResourceLoader::loadTextFile("basicShader.vert"));
	shader.addFragmentShader(ResourceLoader::loadTextFile("basicShader.frag"));
	
	shader.linkShader();
	shader.addUniform("transform");

	

}


Game::~Game()
{
	delete texture;
	//delete sl;
}

double temp;

void Game::update()
{
	temp += Time::getDelta();

	transform.setTranslation(sin(temp), 0, 0);
	transform.setRotation(0.0, sin(temp) , sin(temp));
	shader.setUniform("transform", transform.getTransformation());
}

void Game::render()
{
	shader.bind();
	texture->bind();
	mesh.draw();
	//sl->draw();
}

void Game::dispose()
{
	
}
