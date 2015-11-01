#include "Game.h"
#include "Input.h"
#include "Vertex.h"
#include <iostream>
#include <glm/vec3.hpp>

using namespace S3D;

void keyPresed(int key)
{
	std::cout << "key " << char(key) << " pressed!" << std::endl;
}

Game::Game()
{
	S3D::Input::pressed.connect(keyPresed);
	std::vector<Vertex> v;
	v.push_back(glm::vec3(-1, -1, 0));
	v.push_back(glm::vec3(-1, 1, 0));
	v.push_back(glm::vec3(0, 1, 0));
	
	mesh.addVertices(v);
}


Game::~Game()
{
	
}



void Game::update()
{
	
}

void Game::render()
{
	mesh.draw();
}

void Game::dispose()
{

}
