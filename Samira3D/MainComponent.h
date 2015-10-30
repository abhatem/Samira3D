#pragma once

namespace SE {
	class MainComponent
	{
	public:
		MainComponent();
		~MainComponent();


		void start();
		void update();
		void render();
		void dispose();

	private:
		bool m_isRunning;
		double frameCap = 5000.0;
	};
}
