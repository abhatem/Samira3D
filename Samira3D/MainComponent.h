#pragma once

#include "Game.h"

namespace S3D {
	class MainComponent
	{
	public:
		MainComponent();
		~MainComponent();


		void start();
		void update(); //contains main loop
		void render();
		void dispose();

	private:
		bool m_isRunning;
		double frameCap = 5000.0;
		Game *m_game;
	};
}
