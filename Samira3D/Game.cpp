#include "Game.h"
#include "Input.h"
#include <iostream>

void keyPresed(int key)
{

	std::cout << "key " << char(key) << " pressed!" << std::endl;
}

Game::Game()
{
	SE::Input::pressed.connect(keyPresed);
}


Game::~Game()
{
	
}



void Game::update()
{
	
}

void Game::render()
{

}

void Game::dispose()
{

}
