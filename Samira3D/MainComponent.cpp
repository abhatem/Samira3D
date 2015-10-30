#include "MainComponent.h"
#include "Time.h"
#include "Window.h"
#include <iostream>
#include <GLFW\glfw3.h>
#include <thread>
#include <chrono>
using namespace SE;

MainComponent::MainComponent()
{
	Window::init();
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
	update();
}

void MainComponent::update()
{
	int frames = 0;
	double frameCounter = 0;
	bool shouldRender = false;
	double frameTime = 1.0 / frameCap;
	double lastTime = Time::getTime();
	double unprocessedTime = 0;
	while (m_isRunning){
		double startTime = Time::getTime();
		double passedTime = startTime - lastTime;
		lastTime = startTime;
		unprocessedTime += passedTime;
		frameCounter += unprocessedTime;
		//std::cout << "Unprocessed: " << unprocessedTime << std::endl;
		while (unprocessedTime > frameTime)
		{
			shouldRender = true;
			unprocessedTime -= frameTime;

			// UPDATE GAME
			Window::update();
			if (Window::shouldClose()) {
				m_isRunning = false;
				//dispose();
			}

			if (frameCounter >= 1)
			{
				std::cout << frames << std::endl;
				frames = 0;
				frameCounter = 0;
			}

			
		}
		if (shouldRender)
		{
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
	Window::render();
}
void MainComponent::dispose()
{
	Window::dispose();
}
