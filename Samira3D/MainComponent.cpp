#include "MainComponent.h"
#include "Time.h"
#include "Window.h"
#include <iostream>
#include <GLFW\glfw3.h>
#include <thread>
#include <chrono>

#include "Input.h"
#include "RenderUtil.h"
#include "Shaders.h"
using namespace S3D;

MainComponent::MainComponent()
{
	Window::init(800, 600, "Samira3D");
	Input::init(Window::getWindowHandle());
	m_isRunning = false;
}


MainComponent::~MainComponent()
{
	dispose();
}


void MainComponent::start()
{
	m_isRunning = true;
	Window::createWindow();
	RenderUtil::initGraphics();
	Shaders::init();
	m_game = new Game();
	
	std::cout << "OpenGL version " << RenderUtil::getOpenGLVersion() << std::endl;
	update();
}

float temp1 = 0;
float temp2 = 0;
//contains main loop
void MainComponent::update()
{
	
	int frames = 0;
	double frameCounter = 0;
	bool shouldRender = false;
	double frameTime = 1.0 / frameCap;
	double lastTime = Time::getTime();
	double unprocessedTime = 0;
	while (m_isRunning){
		
		shouldRender = false;

		double startTime = Time::getTime();
		double passedTime = startTime - lastTime;
		lastTime = startTime;
		unprocessedTime += passedTime;
		
		//frameCounter += unprocessedTime;
		
		frameCounter += passedTime;
		//std::cout << "Unprocessed: " << unprocessedTime << std::endl;
		while (unprocessedTime > frameTime)
		{
			shouldRender = true;
			unprocessedTime -= frameTime;
			
			// UPDATE GAME
			m_game->update();
			Window::update();
			if (Window::shouldClose()) {
				m_isRunning = false;
				//dispose();
			}

			if (frameCounter >= 1.0)
			{
				std::cout << frames << std::endl;
				frames = 0;
				frameCounter = 0;
			}

			
		}
		if (shouldRender)
		{
			Time::setDelta(unprocessedTime);
			render();
			frames++;
		}
		else {
			//std::cout << "sleeping" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		
		
	}
	dispose();
}

void MainComponent::render()
{
	RenderUtil::clearScreen();
	m_game->render();
	Window::render();
	
}
void MainComponent::dispose()
{
	Window::dispose();
	m_game->dispose();
}
