//#include <GL/glew.h>
//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include "Mesh.h"
//#include "Shader.h"
//#include "Transform.h"
//#include "PerspectiveCamera.h"
//#include "RenderPass.h"
//#include "Font.h"
//#include "Text2D.h"
//#include "Lamp.h"
//#include "GeometricMesh.h"
//#include "Texture.h"
//#include "OrthoCamera.h"
//#include "SceneObject.h"
//#include "MeshComp.h"
//#include "MaterialComp.h"
//#include "Globals.h"
//#include "Skybox.h"
//#include "MaterialNormalComp.h"
//#include "IndexedMesh.h"
//
//const GLint WIDTH = 800, HEIGHT = 600;
//
//int main()
//{
//	sf::ContextSettings settings;
//	settings.depthBits = 24;
//	settings.stencilBits = 8;
//	settings.majorVersion = 4;
//	settings.minorVersion = 2;
//	settings.attributeFlags = sf::ContextSettings::Core;
//
//	sf::Window window(sf::VideoMode(WIDTH, HEIGHT, 32), "Engine3", sf::Style::Titlebar | sf::Style::Close, settings);
//	//window.setMouseCursorGrabbed(true);
//	//window.setMouseCursorVisible(false);
//	glewExperimental = GL_TRUE;
//	if (glewInit() != GLEW_OK) {
//		std::cout << "stuff failed" << std::endl;
//		return 1;
//	}
//
//	bool running = true;
//
//
//	//std::vector<GLfloat> triangleData = {
//	//	-1.0f, -1.0f, 0.0f,
//	//	1.0f, -1.0f, 0.0f,
//	//	0.0f,  1.0f, 0.0f,
//	//};
//
//
//	///*std::vector<GLfloat> cubeWithNormalsData = {
//	//-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//	//0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//	//0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//	//0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//	//-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//	//-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//	//-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	//0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	//0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	//0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	//-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	//-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//	//-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//	//-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//	//-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//	//-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//	//-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//	//-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//	//0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//	//0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//	//0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//	//0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//	//0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//	//0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//	//-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//	//0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//	//0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//	//0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//	//-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//	//-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//	//-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//	//0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//	//0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//	//0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//	//-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//	//-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//	//};*/
//
//	//std::vector<GLfloat> cubeWithNormalsData = {
//	//	0.5f,  0.5f, -0.5f, 0.0f,  0.0f, -1.0f,
//	//	0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//	//	-0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f,
//	//	-0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f,
//	//	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//	//	0.5f,  0.5f, -0.5f, 0.0f,  0.0f, -1.0f,
//
//	//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	//	0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	//	0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	//	0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	//	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//	//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//	//	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//	//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//	//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//	//	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//	//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//	//	0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//	//	0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//	//	0.5f,  0.5f,  0.5f, 1.0f,  0.0f,  0.0f,
//	//	0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//	//	0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//	//	0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//
//	//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//	//	0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//	//	0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//	//	0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//	//	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//	//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//	//	0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//	//	0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//	//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//	//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//	//	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//	//	0.5f,  0.5f,  0.5f, 0.0f,  1.0f,  0.0f
//	//};
//
//	//std::vector<GLfloat> cubeDataWithTexNorm = {
//	//	0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//	//	0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
//	//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//	//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//	//	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
//	//	0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//
//	//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
//	//	0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
//	//	0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
//	//	0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
//	//	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
//	//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
//
//	//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//	//	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//	//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//	//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//	//	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//	//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//
//	//	0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//	//	0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//	//	0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//	//	0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//	//	0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//	//	0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//
//	//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//	//	0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
//	//	0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//	//	0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//	//	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
//	//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//
//	//	0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//	//	0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
//	//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
//	//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
//	//	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
//	//	0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f
//	//};
//	//std::vector<GLfloat> cubeData = {
//	//	-1.0f,-1.0f,-1.0f, // triangle 1 : begin
//	//	-1.0f,-1.0f, 1.0f,
//	//	-1.0f, 1.0f, 1.0f, // triangle 1 : end
//	//	1.0f, 1.0f,-1.0f, // triangle 2 : begin
//	//	-1.0f,-1.0f,-1.0f,
//	//	-1.0f, 1.0f,-1.0f, // triangle 2 : end
//	//	1.0f,-1.0f, 1.0f,
//	//	-1.0f,-1.0f,-1.0f,
//	//	1.0f,-1.0f,-1.0f,
//	//	1.0f, 1.0f,-1.0f,
//	//	1.0f,-1.0f,-1.0f,
//	//	-1.0f,-1.0f,-1.0f,
//	//	-1.0f,-1.0f,-1.0f,
//	//	-1.0f, 1.0f, 1.0f,
//	//	-1.0f, 1.0f,-1.0f,
//	//	1.0f,-1.0f, 1.0f,
//	//	-1.0f,-1.0f, 1.0f,
//	//	-1.0f,-1.0f,-1.0f,
//	//	-1.0f, 1.0f, 1.0f,
//	//	-1.0f,-1.0f, 1.0f,
//	//	1.0f,-1.0f, 1.0f,
//	//	1.0f, 1.0f, 1.0f,
//	//	1.0f,-1.0f,-1.0f,
//	//	1.0f, 1.0f,-1.0f,
//	//	1.0f,-1.0f,-1.0f,
//	//	1.0f, 1.0f, 1.0f,
//	//	1.0f,-1.0f, 1.0f,
//	//	1.0f, 1.0f, 1.0f,
//	//	1.0f, 1.0f,-1.0f,
//	//	-1.0f, 1.0f,-1.0f,
//	//	1.0f, 1.0f, 1.0f,
//	//	-1.0f, 1.0f,-1.0f,
//	//	-1.0f, 1.0f, 1.0f,
//	//	1.0f, 1.0f, 1.0f,
//	//	-1.0f, 1.0f, 1.0f,
//	//	1.0f,-1.0f, 1.0f
//	//};
//
//	//std::vector<GLfloat> quadData = {
//	//	1.0f,  1.0f, 0.0f,
//	//	-1.0f, 1.0f, 0.0f,
//	//	-1.0f, -1.0f, 0.0f,
//	//	//----------------
//	//	1.0f,  -1.0f, 0.0f,
//	//	1.0f, 1.0f, 0.0f,
//	//	-1.0f, -1.0f, 0.0f,
//	//};
//
//	//std::vector<GLfloat> quadMeshData = {
//	//	1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 10.0f, 10.0f,
//	//	-1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -10.0f, 10.0f,
//	//	-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -10.0f, -10.0f,
//	//	//----------------
//	//	1.0f,  -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 10.0f, -10.0f,
//	//	1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 10.0f, 10.0f,
//	//	-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -10.0f, -10.0f,
//	//};
//
//	//std::vector<GLfloat> quadMeshDataUnscaled = {
//	//	1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
//	//	-1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, 1.0f,
//	//	-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, -1.0f,
//	//	//----------------
//	//	1.0f,  -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, -1.0f,
//	//	1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
//	//	-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, -1.0f,
//	//};
//
//
//	////std::vector<float> skyboxVertices = {
//	////	// positions          
//	////	-1.0f,  1.0f, -1.0f,
//	////	-1.0f, -1.0f, -1.0f,
//	////	1.0f, -1.0f, -1.0f,
//	////	1.0f, -1.0f, -1.0f,
//	////	1.0f,  1.0f, -1.0f,
//	////	-1.0f,  1.0f, -1.0f,
//
//	////	-1.0f, -1.0f,  1.0f,
//	////	-1.0f, -1.0f, -1.0f,
//	////	-1.0f,  1.0f, -1.0f,
//	////	-1.0f,  1.0f, -1.0f,
//	////	-1.0f,  1.0f,  1.0f,
//	////	-1.0f, -1.0f,  1.0f,
//
//	////	1.0f, -1.0f, -1.0f,
//	////	1.0f, -1.0f,  1.0f,
//	////	1.0f,  1.0f,  1.0f,
//	////	1.0f,  1.0f,  1.0f,
//	////	1.0f,  1.0f, -1.0f,
//	////	1.0f, -1.0f, -1.0f,
//
//	////	-1.0f, -1.0f,  1.0f,
//	////	-1.0f,  1.0f,  1.0f,
//	////	1.0f,  1.0f,  1.0f,
//	////	1.0f,  1.0f,  1.0f,
//	////	1.0f, -1.0f,  1.0f,
//	////	-1.0f, -1.0f,  1.0f,
//
//	////	-1.0f,  1.0f, -1.0f,
//	////	1.0f,  1.0f, -1.0f,
//	////	1.0f,  1.0f,  1.0f,
//	////	1.0f,  1.0f,  1.0f,
//	////	-1.0f,  1.0f,  1.0f,
//	////	-1.0f,  1.0f, -1.0f,
//
//	////	-1.0f, -1.0f, -1.0f,
//	////	-1.0f, -1.0f,  1.0f,
//	////	1.0f, -1.0f, -1.0f,
//	////	1.0f, -1.0f, -1.0f,
//	////	-1.0f, -1.0f,  1.0f,
//	////	1.0f, -1.0f,  1.0f
//	////};
//
//
//	Transform t;
//	t.setTranslation(0, 0, 0);
//	t.setScale(Vec3(1, 1, 1));
//
//	Transform t_plane;
//	t_plane.setTranslation(0, -2.0f, 0);
//	t_plane.setScale(100.0f, 100.0f, 100.0f);
//	t_plane.setRotation(-glm::pi<float>() / 2.0f, Vec3(1.0f, 0.0f, 0.0f));
//	//Mesh m;
//	//Mesh plane;
//
//
//	GeometricMesh quad;
//	quad.init(GLOBAL::quadData);
//	/*GeometricMesh skybox;
//	skybox.init(skyboxVertices);*/
//
//	PerspectiveCamera cam;
//	cam.setProjection(1.0f, 1.333333f, 0.1f, 1000.0f);
//	cam.setTranslation(Vec3(1, 1, 0));
//
//
//	/*m.init(cubeDataWithTexNorm);
//	plane.init(quadMeshData);
//	*/
//
//	MeshComp mComp;
//	mComp.mesh.init(GLOBAL::cubeDataWithTexNorm);
//
//	MeshComp planeComp;
//	planeComp.mesh.init(GLOBAL::quadMeshData);
//
//	MeshComp wallComp;
//	wallComp.mesh.init(GLOBAL::quadMeshDataUnscaled);
//
//	sf::Vector2i center(WIDTH / 2, HEIGHT / 2);
//	sf::Vector2i newCursorPos = sf::Mouse::getPosition(window);
//	//RenderPass rp;
//	//rp.unbind();
//
//	sf::Clock clock;
//
//	Texture diffuseTexture;
//	diffuseTexture.loadFromFile("crate_diff.png");
//
//	Texture specularTexture;
//	specularTexture.loadFromFile("crate_spec.png");
//
//	Texture brickWallDiffuse;
//	brickWallDiffuse.loadFromFile("brickwall.jpg");
//
//	Texture brickWallNormal;
//	brickWallNormal.loadFromFile("brickwall_normal.jpg");
//
//
//	glEnable(GL_BLEND);
//
//
//
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	glFrontFace(GL_CCW);
//	glEnable(GL_DEPTH_TEST);
//
//
//
//
//	Font font;
//	font.init("octagen-roman-ffp.ttf", 30);
//	Text2D text;
//	text.init(&font, "test", 400, 300, 1, glm::vec3(0, 0, 0));
//
//	Shader sh;
//	sh.loadFromFile("MaterialShader.vert", "MaterialShader.frag");
//	Shader framebufferShader;
//	framebufferShader.loadFromFile("framebufferShader.vert", "framebufferShader.frag");
//
//	Shader textShader;
//	textShader.loadFromFile("textShader.vert", "textShader.frag");
//	Shader lampShader;
//	lampShader.loadFromFile("lampShader.vert", "lampShader.frag");
//
//	Shader LightDepthMapshader;
//	LightDepthMapshader.loadFromFile("LightDepthMapShader.vert", "LightDepthMapShader.frag");
//
//	Shader skyboxShader;
//	skyboxShader.loadFromFile("skyboxShader.vert", "skyboxShader.frag");
//
//	Shader materialNormalShader;
//	materialNormalShader.loadFromFile("MaterialNormalShader.vert", "MaterialNormalShader.frag");
//
//	Shader premitiveShader;
//	premitiveShader.loadFromFile("perspectiveFirst.vert", "perspectiveFirst.frag");
//
//	Lamp lamp;
//	lamp.transform.setTranslation(0, 0, 0);
//	lamp.transform.setScale(glm::vec3(0.25f));
//	lamp.setColor(Vec3(1.0, 1.0, 1.0));
//
//
//	MaterialComp mat;
//	mat.shader = sh;
//	mat.diffuseTexture = diffuseTexture;
//	mat.specularTexture = specularTexture;
//	mat.lamp = lamp;
//	mat.lightDepthShader = LightDepthMapshader;
//
//
//	MaterialNormalComp mnc;
//	mnc.shader = materialNormalShader;
//	mnc.lamp = lamp;
//	mnc.diffuseTexture = brickWallDiffuse;
//	mnc.normalTexture = brickWallNormal;
//	mnc.lightDepthShader = LightDepthMapshader;
//
//	SceneObject root;
//	SceneObject boxObj;
//	SceneObject planeObj;
//	SceneObject brickWallObj;
//	root.addChild(&boxObj);
//	root.addChild(&planeObj);
//	root.addChild(&brickWallObj);
//	boxObj.addComponent(1, &mComp);
//	boxObj.addComponent(0, &mat);
//
//	planeObj.addComponent(0, &mat);
//	planeObj.addComponent(1, &planeComp);
//	planeObj.setTransform(t_plane);
//
//	brickWallObj.addComponent(0, &mnc);
//	brickWallObj.addComponent(1, &wallComp);
//	Transform tr;
//	tr.setTranslation(Vec3(3.0f, 0.0f, 0.0f));
//	tr.setScale(1.0f, 1.0f, 1.0f);
//	brickWallObj.setTransform(tr);
//
//	OrthoCamera ocam;
//
//	GLOBAL::scenePass.init();
//	GLOBAL::lightDepthPass.init(1);
//
//
//	Skybox sb;
//	sb.init("skybox/right.jpg", "skybox/left.jpg", "skybox/top.jpg",
//		"skybox/bottom.jpg", "skybox/front.jpg", "skybox/back.jpg");
//
//	IndexedMesh im;
//	std::vector<GLfloat> triangleData2 = {
//		-1.0f, -1.0f, 0.0f,
//		1.0f, -1.0f, 0.0f,
//		0.0f,  1.0f, 0.0f,
//	};
//	std::vector<GLuint> indexData = {
//		0, 1, 2
//	};
//
//
//	std::vector<GLfloat> IndexedQuadMeshData = {
//		1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
//		-1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, 1.0f,
//		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, -1.0f,
//		1.0f,  -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, -1.0f,
//	};
//
//	std::vector<GLuint> quadIndices = {
//		0, 1, 2,
//		2, 3, 0
//	};
//	im.init(IndexedQuadMeshData, quadIndices);
//	Transform it;
//	it.setTranslation(-3.0f, 0.0f, 0.0f);
//	while (running) {
//		sf::Event windowEvent;
//		while (window.pollEvent(windowEvent)) {
//			switch (windowEvent.type) {
//			case sf::Event::Closed:
//				running = false;
//				break;
//			}
//		}
//
//
//
//		newCursorPos = sf::Mouse::getPosition(window);
//		float xd = (newCursorPos.x - center.x) / 10.0f;
//		float yd = (newCursorPos.y - center.y) / 10.0f;
//		cam.rotate(yd, xd);
//		sf::Mouse::setPosition(center, window);
//
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//			cam.move(cam.getForward() / 100.0f);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//			cam.move(-cam.getRight() / 100.0f);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//			cam.move(cam.getRight() / 100.0f);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//			cam.move(-cam.getForward() / 100.0f);
//		}
//		//oldCursorPos = sf::Mouse::getPosition();
//		/*cam.setPitch(localPosition.y/10.0f);
//		cam.setYaw(localPosition.x/10.0f);*/
//		//glClearDepth(0.0);
//		t.calcMatrix();
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		//glClear(GL_COLOR_BUFFER_BIT);
//		Mat4 dbg = t.getMatrix();
//		//glm::mat4 proj = glm::ortho(0, 1, 0, 1, 0, 100);
//		Mat4 MVP = cam.projection() *
//			cam.view() *
//			//glm::lookAt(ocam.getTransform().getTranslation(), Vec3(0, 0, 0), Vec3(0, 1, 0)) *
//			t.getMatrix();
//
//		//ocam.setProjection(-1.0f, 1.0f, 1.0f, -1.0f, -1000.0f, 1000.0f);
//		mat.lamp.transform.setTranslation(Vec3(5 * cos(clock.getElapsedTime().asSeconds()), 5.0f, 5 * sin(clock.getElapsedTime().asSeconds())));
//		mnc.lamp.transform.setTranslation(Vec3(5 * cos(clock.getElapsedTime().asSeconds()), 5.0f, 5 * sin(clock.getElapsedTime().asSeconds())));
//		//ocam.setTranslation(mat.lamp.transform.getTranslation());
//		/*std::cout << ocam.getTransform().getTranslation().x << " " << ocam.getTransform().getTranslation().y << " " <<
//		ocam.getTransform().getTranslation().z << std::endl;
//		*/
//		//ocam.lookAt(Vec3(0.0f, 0.0f, 0.0f));
//		GLOBAL::scenePass.bind();
//
//		//glClear(GL_COLOR_BUFFER_BIT);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//------------------
//		//sh.use();
//		////sh.updateUniformVec3("material.ambient", Vec3(0.19125f, 0.0735f, 0.0225f));
//
//		////sh.updateUniformVec3("material.diffuse", Vec3(0.7038f, 0.27048f, 0.0828f));
//		//diffuseTexture.bind(0);
//		//sh.updateUniformInt("material.diffuse", 0); // GL_TEXTURE0
//
//		//specularTexture.bind(1); //GL_TEXTURE1
//		//sh.updateUniformInt("material.specular", 1); //GL_TEXTURE1
//
//		////sh.updateUniformVec3("material.specular", Vec3(0.256777f, 0.137622f, 0.086014f));
//		//sh.updateUniformFloat("material.shininess", 32.0f);
//		//sh.updateUniformVec3("light.ambient", Vec3(0.1f, 0.1f, 0.1f));
//		//sh.updateUniformVec3("light.diffuse", Vec3(1.0f, 1.0f, 1.0f));
//		//sh.updateUniformVec3("light.specular", Vec3(1.0f, 1.0f, 1.0f));
//		//sh.updateUniformVec3("light.position", lamp.transform.getTranslation());
//		//sh.updateUniformMat4("modelMat", t.getMatrix());
//		//sh.updateUniformMat4("MVP", MVP);
//		//sh.updateUniformVec3("lightColor", lamp.getColor());
//		//sh.updateUniformVec3("objectColor", Vec3(1.0, 1.0, 0.0));
//		//sh.updateUniformVec3("lightPosition", lamp.transform.getTranslation());
//		//sh.updateUniformMat3("normalMat", glm::mat3(glm::transpose(glm::inverse(t.getMatrix()))));
//		//sh.updateUniformVec3("viewPos", cam.getTransform().getTranslation());
//		////sh.updateUniformFloat("specularIntensity", 0.5f);
//		//m.draw();
//
//		//lamp.transform.calcMatrix();
//
//		//Mat4 MVP2 =  cam.projection() *
//		//	cam.view() *
//		//	lamp.transform.getMatrix();
//		//lampShader.use();
//		//lampShader.updateUniformMat4("MVP", MVP2);
//		//lampShader.updateUniformVec3("color", lamp.getColor());
//		//
//		//lamp.draw();
//
//		//t_plane.calcMatrix();
//		//Mat4 MVP_Plane = cam.projection() * cam.view() * t_plane.getMatrix();
//		//
//		//sh.use();
//		////sh.updateUniformVec3("material.ambient", Vec3(0.19125f, 0.0735f, 0.0225f));
//
//		////sh.updateUniformVec3("material.diffuse", Vec3(0.7038f, 0.27048f, 0.0828f));
//		//diffuseTexture.bind(0);
//		//sh.updateUniformInt("material.diffuse", 0); // GL_TEXTURE0
//
//		//specularTexture.bind(1); //GL_TEXTURE1
//		//sh.updateUniformInt("material.specular", 1); //GL_TEXTURE1
//
//		////sh.updateUniformVec3("material.specular", Vec3(0.256777f, 0.137622f, 0.086014f));
//		//sh.updateUniformFloat("material.shininess", 2.0f);
//		//sh.updateUniformVec3("light.ambient", Vec3(0.1f, 0.1f, 0.1f));
//		//sh.updateUniformVec3("light.diffuse", Vec3(1.0f, 1.0f, 1.0f));
//		//sh.updateUniformVec3("light.specular", Vec3(1.0f, 1.0f, 1.0f));
//		//sh.updateUniformVec3("light.position", lamp.transform.getTranslation());
//		//sh.updateUniformMat4("modelMat", t_plane.getMatrix());
//		//sh.updateUniformMat4("MVP", MVP_Plane);
//		//sh.updateUniformVec3("lightColor", lamp.getColor());
//		//sh.updateUniformVec3("objectColor", Vec3(1.0, 1.0, 0.0));
//		//sh.updateUniformVec3("lightPosition", lamp.transform.getTranslation());
//		//sh.updateUniformMat3("normalMat", glm::mat3(glm::transpose(glm::inverse(t_plane.getMatrix()))));
//		//sh.updateUniformVec3("viewPos", cam.getTransform().getTranslation());
//		////sh.updateUniformFloat("specularIntensity", 0.5f);
//		//plane.draw();
//		//---------------------
//		//ocam.lookAt(glm::vec3(0.0f, 0.0f, 0.0f));
//
//		root.render(&cam);
//		premitiveShader.use();
//		it.calcMatrix();
//		premitiveShader.updateUniformMat4("MVP", cam.projection() * cam.view() * it.getMatrix());
//		im.draw();
//		sb.draw(&cam, skyboxShader); // draw skybox at the end.
//
//		GLOBAL::scenePass.unbind();
//
//
//
//		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		mat.lamp.renderDepthMap(root);
//
//		GLOBAL::scenePass.bindTexture();
//
//		//mat.lamp.bindDepthMap();
//
//		framebufferShader.use();
//		framebufferShader.updateUniformInt("renderedTexture", 0);
//		framebufferShader.updateUniformFloat("time", clock.getElapsedTime().asSeconds());
//		quad.draw();
//		/*window.draw(text);*/
//		text.m_x = 400 + 200 * sin(clock.getElapsedTime().asSeconds());
//		text.m_y = 300 + 150 * cos(clock.getElapsedTime().asSeconds());
//		text.draw(textShader);
//		window.display();
//
//
//
//	}
//	window.close();
//	return 0;
//}