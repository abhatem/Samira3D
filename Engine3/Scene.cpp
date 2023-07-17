#include "Scene.h"
#include "Globals.h"
#include "AssimpImporter.h"
#include <iostream>
void Scene::init()
{
	Transform t;
	t.setTranslation(0, 0, 0);
	t.setScale(Vec3(1, 1, 1));

	Transform t_plane;
	t_plane.setTranslation(0, -2.0f, 0);
	t_plane.setScale(100.0f, 100.0f, 100.0f);
	t_plane.setRotation(-glm::pi<float>() / 2.0f, Vec3(1.0f, 0.0f, 0.0f));


	

	screenQuad.init(GLOBAL::quadData);


	/*PerspectiveCamera cam;*/
	
	cam.setProjection(1.0f, (float)GLOBAL::width/(float)GLOBAL::height, 0.1f, 1000.0f);
	cam.setTranslation(Vec3(1, 1, 0));
	pCameras["cam"] = cam;


	meshes["cube"].init(GLOBAL::cubeDataWithTexNorm);
	meshes["plane"].init(GLOBAL::quadMeshData);
	meshes["wall"].init(GLOBAL::quadMeshDataUnscaled);

	meshComponents["mComp"].mesh = &meshes["cube"];

	meshComponents["planeComp"].mesh = &meshes["plane"];
	
	meshComponents["wallComp"].mesh = &meshes["wall"];


	Texture diffuseTexture;
	diffuseTexture.loadFromFile("crate_diff.png");
	textures["diffuseTexture"] = diffuseTexture;

	Texture specularTexture;
	specularTexture.loadFromFile("crate_spec.png");
	textures["specularTexture"] = specularTexture;

	Texture brickWallDiffuse;
	brickWallDiffuse.loadFromFile("brickwall.jpg");
	textures["brickWallDiffuse"] = brickWallDiffuse;

	Texture brickWallNormal;
	brickWallNormal.loadFromFile("brickwall_normal.jpg");
	textures["brickWallNormal"] = brickWallNormal;

	glEnable(GL_BLEND);



	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);




	Font font;
	font.init("octagen-roman-ffp.ttf", 30);
	fonts["main"] = font;

	texts["test"].init(&fonts["main"], "test", GLOBAL::width/2, GLOBAL::height/2, 1.0f, glm::vec3(0, 0, 0));


	Shader sh;
	sh.loadFromFile("MaterialShader.vert", "MaterialShader.frag");
	shaders["MaterialShader"] = sh;

	Shader framebufferShader;
	framebufferShader.loadFromFile("framebufferShader.vert", "framebufferShader.frag");
	shaders["framebufferShader"] = framebufferShader;

	Shader textShader;
	textShader.loadFromFile("textShader.vert", "textShader.frag");
	shaders["textShader"] = textShader;

	Shader lampShader;
	lampShader.loadFromFile("lampShader.vert", "lampShader.frag");
	shaders["lampShader"] = lampShader;

	Shader lightDepthMapShader;
	lightDepthMapShader.loadFromFile("LightDepthMapShader.vert", "LightDepthMapShader.frag");
	shaders["lightDepthMapShader"] = lightDepthMapShader;

	Shader skyboxShader;
	skyboxShader.loadFromFile("skyboxShader.vert", "skyboxShader.frag");
	shaders["skyboxShader"] = skyboxShader;

	Shader materialNormalShader;
	materialNormalShader.loadFromFile("MaterialNormalShader.vert", "MaterialNormalShader.frag");
	shaders["materialNormalShader"] = materialNormalShader;

	Shader primitiveShader;
	primitiveShader.loadFromFile("perspectiveFirst.vert", "perspectiveFirst.frag");
	shaders["primitiveShader"] = primitiveShader;

	shaders["standardShader"].loadFromFile("standardShader.vert", "standardShader.frag");


	Lamp lamp;
	lamp.transform.setTranslation(0, 0, 0);
	lamp.transform.setScale(glm::vec3(0.25f));
	lamp.setColor(Vec3(1.0, 1.0, 1.0));
	lamps["lamp1"] = lamp;


	MaterialComp mat;
	mat.shader = &shaders["MaterialShader"];
	mat.diffuseTexture = &textures["diffuseTexture"];
	mat.specularTexture = &textures["specularTexture"];
	mat.lamp = &lamps["lamp1"];
	mat.lightDepthShader = &shaders["lightDepthMapShader"];
	materialComponents["mat"] = mat;

	MaterialNormalComp mnc;
	mnc.shader = &shaders["materialNormalShader"];
	mnc.lamp = &lamps["lamp1"];
	mnc.diffuseTexture = &textures["brickWallDiffuse"];
	mnc.normalTexture = &textures["brickWallNormal"];
	mnc.lightDepthShader = &shaders["lightDepthMapShader"];
	materialNormalComponents["mnc"] = mnc;

	

	SceneObject root;
	SceneObject boxObj;
	SceneObject planeObj;
	SceneObject brickWallObj;
	
	sceneObjects["root"] = root;
	sceneObjects["boxObj"] = boxObj;
	sceneObjects["planeObj"] = planeObj;
	sceneObjects["brickWallObj"] = brickWallObj;

	sceneObjects["boxObj"].addComponent(1, &meshComponents["mComp"]);
	sceneObjects["boxObj"].addComponent(0, &materialComponents["mat"]);

	sceneObjects["planeObj"].addComponent(0, &materialComponents["mat"]);
	sceneObjects["planeObj"].addComponent(1, &meshComponents["planeComp"]);
	sceneObjects["planeObj"].setTransform(t_plane);

	sceneObjects["brickWallObj"].addComponent(0, &materialNormalComponents["mnc"]);
	sceneObjects["brickWallObj"].addComponent(1, &meshComponents["wallComp"]);
	Transform tr;
	tr.setTranslation(Vec3(3.0f, 0.0f, 0.0f));
	tr.setScale(1.0f, 1.0f, 1.0f);
	sceneObjects["brickWallObj"].setTransform(tr);

	

	sceneObjects["root"].addChild(&sceneObjects["boxObj"]);
	sceneObjects["root"].addChild(&sceneObjects["planeObj"]);
	sceneObjects["root"].addChild(&sceneObjects["brickWallObj"]);

	OrthoCamera ocam;
	oCameras["ocam"] = ocam;
	GLOBAL::scenePass.init();
	GLOBAL::lightDepthPass.init(1);

	//IndexedMesh im;
	//im.init(GLOBAL::IndexedQuadMeshData, GLOBAL::quadIndices);
	//indexedMeshes["im"] = im;



	skybox.init("skybox/right.jpg", "skybox/left.jpg", "skybox/top.jpg",
		"skybox/bottom.jpg", "skybox/front.jpg", "skybox/back.jpg");


	sf::Vector2i center(GLOBAL::width / 2, GLOBAL::height / 2);
	cursorPos = sf::Mouse::getPosition(GLOBAL::window);
	
	textures["wood_barrel_diffuse"].loadFromFile("wood_barrels/big_diffus.tga");
	textures["wood_barrel_specular"].loadFromFile("wood_barrels/big_specular.tga");
	textures["wood_barrel_normal"].loadFromFile("wood_barrels/big_normal.tga");
	standardMaterialComponents["wood_barrel_mat"].diffuseTexture = &textures["wood_barrel_diffuse"];
	standardMaterialComponents["wood_barrel_mat"].specularTexture = &textures["wood_barrel_specular"];
	standardMaterialComponents["wood_barrel_mat"].normalTexture = &textures["wood_barrel_normal"];
	standardMaterialComponents["wood_barrel_mat"].lamp = &lamps["lamp1"];
	standardMaterialComponents["wood_barrel_mat"].lightDepthShader = &shaders["lightDepthMapShader"];
	standardMaterialComponents["wood_barrel_mat"].shader = &shaders["standardShader"];
	
	GLOBAL::AssimpImporter.import("wood_barrels/big_wood_barrel.obj", this, &sceneObjects["root"]);
	Transform trans = sceneObjects["wood_barrel_big"].getLocalTransform();
	trans.setScale(0.01f, 0.01f, 0.01f);
	trans.setTranslation(-3.0f, 0.0f, 0.0f);
	sceneObjects["wood_barrel_big"].setTransform(trans);
	sceneObjects["wood_barrel_big"].removeComponent(&materialComponents["mat"]);
	sceneObjects["wood_barrel_big"].addComponent(0, &standardMaterialComponents["wood_barrel_mat"]);


	textures["rock_diffuse"].loadFromFile("rocks/01/diffuse.tga");
	textures["rock_specular"].loadFromFile("rocks/01/specular.tga");
	textures["rock_normal"].loadFromFile("rocks/01/normal.tga");
	standardMaterialComponents["rock_mat"].diffuseTexture = &textures["rock_diffuse"];
	standardMaterialComponents["rock_mat"].specularTexture = &textures["rock_specular"];
	standardMaterialComponents["rock_mat"].normalTexture = &textures["rock_normal"];
	standardMaterialComponents["rock_mat"].lamp = &lamps["lamp1"];
	standardMaterialComponents["rock_mat"].lightDepthShader = &shaders["lightDepthMapShader"];
	standardMaterialComponents["rock_mat"].shader = &shaders["standardShader"];
	GLOBAL::AssimpImporter.import("rocks/01/rock_01.obj", this, &sceneObjects["root"]);
	Transform trans2 = sceneObjects["rock_01"].getLocalTransform();
	trans2.setScale(0.01f, 0.01f, 0.01f);
	trans2.setTranslation(5.0f, 0.0f, 0.0f);
	sceneObjects["rock_01"].setTransform(trans2);
	sceneObjects["rock_01"].addComponent(0, &standardMaterialComponents["rock_mat"]);
	sceneObjects["rock_01"].removeComponent(&materialComponents["mat"]);
	

	/*GLOBAL::AssimpImporter.import("coneCube.obj", this, &sceneObjects["root"]);
	sceneObjects["Cone"].removeComponent(&materialComponents["mat"]);
	sceneObjects["Cube"].removeComponent(&materialComponents["mat"]);
	sceneObjects["Cube"].removeComponent(&indexedMeshComponents["Cube"]);*/
	
	//GLOBAL::AssimpImporter.import("cone.obj", this, &sceneObjects["root"]);
	/*indexedMeshComponents["coneComp"].mesh = &indexedMeshes["Cone"];
	indexedMeshComponents["cubeComp"].mesh = &indexedMeshes["Cube"];
	sceneObjects["coneObj"].addComponent(1, &indexedMeshComponents["coneComp"]);
	sceneObjects["coneObj"].addComponent(1, &indexedMeshComponents["cubeComp"]);
	sceneObjects["coneObj"].addComponent(0, &materialComponents["mat"]);
	Transform coneTr;
	coneTr.setTranslation(0.0f, -2.0f, 3.0f);
	sceneObjects["coneObj"].setTransform(coneTr);
	sceneObjects["root"].addChild(&sceneObjects["coneObj"]);*/

	//sceneObjects["root"].addChild(&sceneObjects["Cone"]);
}

void Scene::render()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		cursorPos = sf::Mouse::getPosition(GLOBAL::window);
		float xd = (cursorPos.x - center.x) / 10.0f;
		float yd = (cursorPos.y - center.y) / 10.0f;
		pCameras["cam"].rotate(yd, xd);
		sf::Mouse::setPosition(center, GLOBAL::window);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			pCameras["cam"].move(pCameras["cam"].getForward() / 100.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			pCameras["cam"].move(-pCameras["cam"].getRight() / 100.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			pCameras["cam"].move(pCameras["cam"].getRight() / 100.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			pCameras["cam"].move(-pCameras["cam"].getForward() / 100.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			pCameras["cam"].rotate(0, 0, 0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			pCameras["cam"].rotate(0, 0, -0.1f);
		}
	}
	
	//cam = pCameras["cam"];
	materialComponents["mat"].lamp->transform.setTranslation(Vec3(5 * cos(clock.getElapsedTime().asSeconds()), 5.0f, 5 * sin(clock.getElapsedTime().asSeconds())));
	materialNormalComponents["mnc"].lamp->transform.setTranslation(Vec3(5 * cos(clock.getElapsedTime().asSeconds()), 5.0f, 5 * sin(clock.getElapsedTime().asSeconds())));
	//--------
	/*mat.lamp.transform.setTranslation(Vec3(5 * cos(clock.getElapsedTime().asSeconds()), 5.0f, 5 * sin(clock.getElapsedTime().asSeconds())));
	mnc.lamp.transform.setTranslation(Vec3(5 * cos(clock.getElapsedTime().asSeconds()), 5.0f, 5 * sin(clock.getElapsedTime().asSeconds())));*/
	//--------


	sceneObjects["root"].render(&pCameras["cam"]);
	Transform it;
	it.setTranslation(-3.0f, 0.0f, 0.0f);
	IndexedMesh im;
	std::vector<Vertex> vertices;
	Vertex v1, v2, v3, v4;

	std::vector<GLfloat> quadMeshDataUnscaled = {
		1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, -1.0f,
		//----------------
		1.0f,  -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, -1.0f,
		1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, -1.0f,
	};
	v1.position = { 1.0f, 1.0f, 0.0f };
	v2.position = { -1.0f, 1.0f, 0.0f };
	v3.position = { -1.0f, -1.0f, 0.0f };
	v4.position = { 1.0f, -1.0f, 0.0f };
	vertices    = { v1, v2, v3, v4 };
	std::vector<GLuint> indices = {
		0, 1, 2,
		2, 3, 0
	};
	im.init(vertices, indices);

	shaders["primitiveShader"].use();
	it.calcMatrix();
	shaders["primitiveShader"].updateUniformMat4("MVP", cam.projection() * cam.view() * it.getMatrix());
	im.draw();



	skybox.draw(&pCameras["cam"], shaders["skyboxShader"]);
	

}

void Scene::renderShadowMap()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*materialComponents["mat"].lamp->renderDepthMap(sceneObjects["root"]);
	materialNormalComponents["mnc"].lamp->renderDepthMap(sceneObjects["root"]);*/
	for (auto &it : lamps) {
		it.second.renderDepthMap(sceneObjects["root"]);
	}
	//------------
	/*mat.lamp.renderDepthMap(sceneObjects["root"]);
	mnc.lamp.renderDepthMap(sceneObjects["root"]);*/
	//------------
}

void Scene::renderScreenQuad()
{
	GLOBAL::scenePass.bindTexture();

	//mat.lamp.bindDepthMap();

	shaders["framebufferShader"].use();
	shaders["framebufferShader"].updateUniformInt("renderedTexture", 0);
	shaders["framebufferShader"].updateUniformFloat("time", clock.getElapsedTime().asSeconds());
	screenQuad.draw();
}

void Scene::renderText()
{
	texts["test"].draw(shaders["textShader"]);
	texts["test"].m_x = GLOBAL::width/2 + 200 * sin(clock.getElapsedTime().asSeconds());
	texts["test"].m_y = GLOBAL::height / 2 + 150 * cos(clock.getElapsedTime().asSeconds());
}
