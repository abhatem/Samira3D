#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "PerspectiveCamera.h"
#include "RenderPass.h"
#include "Font.h"
#include "Text2D.h"
#include "Lamp.h"
#include "GeometricMesh.h"
#include "Texture.h"
#include "OrthoCamera.h"
#include "SceneObject.h"
#include "MeshComp.h"
#include "MaterialComp.h"
#include "Globals.h"
#include "Skybox.h"
#include "MaterialNormalComp.h"
#include "IndexedMesh.h"
#include "Scene.h"

//const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 4;
	settings.minorVersion = 2;
	settings.attributeFlags = sf::ContextSettings::Core;

	//GLOBAL::window.create(sf::VideoMode(GLOBAL::width, GLOBAL::height, 32), "Engine3", sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen, settings);
	GLOBAL::window.create(sf::VideoMode(GLOBAL::width, GLOBAL::height, 32), "Samira3D", sf::Style::Titlebar | sf::Style::Close, settings);

	//window.setMouseCursorGrabbed(true);
	//window.setMouseCursorVisible(false);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "stuff failed" << std::endl;
		return 1;
	}

	bool running = true;
	
	glEnable(GL_BLEND);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);
	
	Transform it;
	it.setTranslation(-3.0f, 0.0f, 0.0f);
	Scene scene;
	scene.init();
	while (running) {
		sf::Event windowEvent;
		while (GLOBAL::window.pollEvent(windowEvent)) {
			switch (windowEvent.type) {
			case sf::Event::Closed:
				running = false;
				break;
			}
		}



		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		scene.renderShadowMap();
		
		GLOBAL::scenePass.bind();
		
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		scene.render();
	
		
		GLOBAL::scenePass.unbind();

		
		scene.renderScreenQuad();
		scene.renderText();
		


	/*	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		mat.lamp.renderDepthMap(root);*/



		GLOBAL::window.display();
		
		

	}
	GLOBAL::window.close();
	return 0;
}