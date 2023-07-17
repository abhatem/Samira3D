#pragma once
#include <vector>
#include "SceneObject.h"
#include "IndexedMesh.h"
#include "Mesh.h"
#include "Component.h"
#include "Shader.h"
#include "Texture.h"
#include "Skybox.h"
#include "GeometricMesh.h"
#include "CameraAbstract.h"
#include "Lamp.h"
#include <map>
#include <unordered_map>
#include <string>
#include "MeshComp.h"
#include "MaterialComp.h"
#include "MaterialNormalComp.h"
#include "IndexedMeshComp.h"
#include "PerspectiveCamera.h"
#include "OrthoCamera.h"
#include "Font.h"
#include "Text2D.h"
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "StandardMaterialComp.h"
#include "DirectionalLight.h"

class Scene {
public:
	
	Scene() {}
	virtual ~Scene() {}

	// maps with names so that scenes are easier to load and save;

	std::map<std::string, SceneObject>				sceneObjects;
	//std::map<std::string, Component>				components;
	std::map<std::string, Mesh>						meshes;
	std::map<std::string, IndexedMesh>				indexedMeshes;
	std::map<std::string, Shader>					shaders;
	std::map<std::string, Texture>					textures;
	//std::map<std::string, CameraAbstract>			cameras;
	std::map<std::string, PerspectiveCamera>		pCameras;
	std::map<std::string, OrthoCamera>				oCameras;
	std::map<std::string, Lamp>						lamps;
	std::map<std::string, MeshComp>					meshComponents;
	std::map<std::string, IndexedMeshComp>			indexedMeshComponents;
	std::map<std::string, MaterialComp>				materialComponents;
	std::map<std::string, MaterialNormalComp>		materialNormalComponents;
	std::map<std::string, Font>						fonts;
	std::map<std::string, Text2D>					texts;
	std::map<std::string, StandardMaterialComp>		standardMaterialComponents;
	std::map<std::string, DirectionalLight>			directionalLights;
	SceneObject        root;
	SceneObject        boxObj;
	SceneObject        planeObj;
	SceneObject        brickWallObj;
	MaterialNormalComp mnc;
	MaterialComp       mat;
	MeshComp           mComp;
	MeshComp           planeComp;
	MeshComp           wallComp;
	PerspectiveCamera  cam;
	Lamp               lamp;

	sf::Clock			clock;
	sf::Vector2i		center = sf::Vector2i(GLOBAL::width / 2, GLOBAL::height / 2);
	sf::Vector2i		cursorPos;
	Skybox				skybox;
	GeometricMesh		screenQuad;

	void init();
	void render();
	void renderShadowMap();
	void renderScreenQuad();
	void renderText();

	// add function to get resource (e.g texture) and if not found to return a default resource.
};
