#include "Game.h"
#include "Input.h"
#include "Vertex.h"
#include "Time.h"
#include "ResourceLoader.h"
#include <iostream>
#include <glm/vec3.hpp>
#include <glm/gtc/constants.hpp>
#include "Shaders.h"
#include <boost/smart_ptr/shared_ptr.hpp>
#include "Cameras.h"

//#include "SceneLoader.h"
using namespace S3D;

void Game::keyRepeat(int key)
{
	//std::cout << "key " << char(key) << " pressed!" << std::endl;
	if (key == GLFW_KEY_W)
	{
		//cam->setPosition(cam->getPosition().x, cam->getPosition().y, cam->getPosition().z + 0.05);
		//cam->setLookAtPos(cam->getLookAtPos().x, cam->getLookAtPos().y, cam->getLookAtPos().z + 0.05);
		std::cout << "let's go forward" << std::endl;
	}
	
	if (key == GLFW_KEY_S)
	{
		//cam->setPosition(cam->getPosition().x, cam->getPosition().y, cam->getPosition().z - 0.05);
		//cam->setLookAtPos(cam->getLookAtPos().x, cam->getLookAtPos().y, cam->getLookAtPos().z - 0.05);
		std::cout << "let's go back" << std::endl;
	}
	
	if (key == GLFW_KEY_UP)
	{
		//cam->setPosition(cam->getPosition().x, cam->getPosition().y, cam->getPosition().z + 5);
		//cam->setLookAtPos(cam->getLookAtPos().x, cam->getLookAtPos().y+0.05f, cam->getLookAtPos().z);
		std::cout << "let's look up" << std::endl;
	}

	if (key == GLFW_KEY_DOWN)
	{
		//cam->setPosition(cam->getPosition().x, cam->getPosition().y, cam->getPosition().z + 5);
		//cam->setLookAtPos(cam->getLookAtPos().x, cam->getLookAtPos().y - 0.05f, cam->getLookAtPos().z);
		std::cout << "let's look down" << std::endl;
	}
}

Game::Game()
{
	//S3D::Input::pressed.connect(&Game::keyPresed);
	//Input::pressed
	Input::repeat.connect(boost::bind(&Game::keyRepeat, this, _1));
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
	mesh.addVertices(v, ind);
	
	//transform.setProjection(70, )

	
	
	//texture = new Texture(ResourceLoader::loadTexture("test.png"));
	material = new S3D::Material(boost::shared_ptr<Texture>(new Texture(ResourceLoader::loadTexture("test.png"))), glm::vec3(1, 0, 1));
	
	//mat(material->getTexture(), material->getColor());


	//sl = new SceneLoader("Samira.obj");
	transform.setProjection(45.0f, Window::getWidth(), Window::getHeight(), 0.1f, 10000.0f);
	/*shader.addVertexShader(ResourceLoader::loadTextFile("basicShader.vert"));
	shader.addFragmentShader(ResourceLoader::loadTextFile("basicShader.frag"));*/
	
	//shader.linkShader();
	//shader.addUniform("transform");
	/*shader.addUniform("CameraMat");
	shader.addUniform("projectionMat");*/
	//shader.addUniform("rotation");
	//shader.addUniform("scale");

	//cam = new Camera(glm::vec3(4, 3, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	
	Shaders::phongShader->setAmbientLight(glm::vec3(0.5, 0.5, 0.5));
	Cameras::addCamera(Camera(glm::vec3(4, 3, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));

}


Game::~Game()
{
	//delete texture;
	delete material;
	//delete sl;
	//delete cam;
}

double temp;

void Game::update()
{
	temp += Time::getDelta();

	//transform.setTranslation(sin(temp), 0, -1);
	//transform.setRotation(0.0, sin(temp) , sin(temp));
	transform.setRotation(sin(temp), glm::vec3(0, 1, 0));
	//transform.setRotation(sin(temp), glm)
	//shader.setUniform("transform", transform.getProjectedTransformation() * cam->getCamMatrix());
	//Shaders::phongShader->updateUniforms(transform.getTransformationMatrix(), transform.getProjectionMatrix()*cam->getCamMatrix()*transform.getTransformationMatrix(), material);
	Shaders::phongShader->updateUniforms(transform.getTransformationMatrix(), transform.getProjectedTransformation(), material);
	//shader.setUniform("transform", transform.getProjectionMatrix()*cam->getCamMatrix()*transform.getTransformationMatrix());
	/*shader.setUniform("translation", transform.getTranslationMatrix());
	shader.setUniform("rotation", transform.getRotationMatrix());
	shader.setUniform("scale", transform.getScale());
	*/
	//shader.setUniform("projectionMat", transform.getProjectedTransformation());
	//shader.setUniform("CameraMat", cam->getCamMatrix());
	
}

void Game::render()
{
	//shader.bind();
	Shaders::phongShader->bind();
	//texture->bind();
	
	
	mesh.draw();
	//sl->draw();
}

void Game::dispose()
{
	
}
