#pragma once
#include <string>

class aiMesh;
class aiScene;
class aiNode;
class Scene;
class SceneObject;
class _AssimpImporter {
public:
	_AssimpImporter() {};
	void import(const std::string &filename, Scene *sc, SceneObject *parentObject);

private:
	void recursiveProcess(aiNode *node, const aiScene *scene, Scene *sc, SceneObject *parentObject);
	void processMesh(aiMesh *mesh, const aiNode *node, const aiScene *scene, Scene *sc, SceneObject *parentObject);
	//SceneObject *parent;
};

