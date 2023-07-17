#include "AssimpImporter.h"
#include "Scene.h"
#include "SceneObject.h"
#include <assimp/matrix4x4.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp> // linker error if I include this at first... weird!

#include <iostream>
void _AssimpImporter::import(const std::string &filename, Scene *sc, SceneObject *parentObject)
{
	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(filename.c_str(),
		aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

	if (!scene) {
		std::cerr << "can\'t load " << filename << std::endl;
		return;
	}

	/*recursiveProcess(scene->mRootNode, scene, sc, parentObject);*/
	for (unsigned int i = 0; i < scene->mRootNode->mNumChildren; i++) {
		recursiveProcess(scene->mRootNode->mChildren[i], scene, sc, parentObject);
	}
}

void _AssimpImporter::recursiveProcess(aiNode * node, const aiScene *scene, Scene *sc, SceneObject *parentObject)
{

	// get transformation of current node
	Transform tr;
	aiQuaternion aiRotation;
	aiVector3D aiTranslation;
	aiVector3D aiScale;
	node->mTransformation.Decompose(aiScale, aiRotation, aiTranslation);

	glm::quat rotation;
	rotation.x = aiRotation.x;
	rotation.y = aiRotation.y;
	rotation.z = aiRotation.z;
	rotation.w = aiRotation.w;

	glm::vec3 translation;
	translation.x = aiTranslation.x;
	translation.y = aiTranslation.y;
	translation.z = aiTranslation.z;

	glm::vec3 scale;
	scale.x = aiScale.x;
	scale.y = aiScale.y;
	scale.z = aiScale.z;


	tr.setTranslation(translation);
	tr.setRotation(rotation);
	tr.setScale(scale);

	// generate name for new scene object
	std::string sceneObjectName;
	if (sc->sceneObjects.find(node->mName.C_Str()) == sc->sceneObjects.end()) {
		sceneObjectName = node->mName.C_Str();
	}
	else {
		unsigned int i = 1;
		while (sc->sceneObjects.find(std::string(node->mName.C_Str()) + std::to_string(i)) != sc->sceneObjects.end()) {
			++i;
		}
		sceneObjectName = std::string(node->mName.C_Str()) + std::to_string(i);
	}
	// create new scene object
	sc->sceneObjects[sceneObjectName].setTransform(tr);

	std::cout << "created scene object named " << sceneObjectName << std::endl;

	parentObject->addChild(&sc->sceneObjects[sceneObjectName]);


	// process meshes
	for (unsigned int i = 0; i < node->mNumMeshes; i++) {
		aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
		processMesh(mesh, node, scene, sc, &sc->sceneObjects[sceneObjectName]);
	}

	
	// walk through the nodes present in the model
	for (unsigned int i = 0; i < node->mNumChildren; i++) {
		recursiveProcess(node->mChildren[i], scene, sc, &sc->sceneObjects[sceneObjectName]);
	}


}

void _AssimpImporter::processMesh(aiMesh * mesh, const aiNode * node, const aiScene * scene, Scene *sc, SceneObject *object)
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	for (unsigned int i = 0; i < mesh->mNumVertices; i++) {

		Vertex temp;
		Vec3 tempVec;

		tempVec.x = mesh->mVertices[i].x;
		tempVec.y = mesh->mVertices[i].y;
		tempVec.z = mesh->mVertices[i].z;


		temp.position = tempVec;

		if (mesh->mNormals) {

			tempVec.x = mesh->mNormals[i].x;
			tempVec.y = mesh->mNormals[i].y;
			tempVec.z = mesh->mNormals[i].z;
		}
		else {

			tempVec.x = tempVec.y = tempVec.z = 0;
		}

		temp.normal = tempVec;

		if (mesh->mTangents) {

			tempVec.x = mesh->mTangents[i].x;
			tempVec.y = mesh->mTangents[i].y;
			tempVec.z = mesh->mTangents[i].z;
		}
		else {
			tempVec.x = tempVec.y = tempVec.z = 0;
		}

		temp.tangent = tempVec;

		//Uint numColors = mesh->GetNumColorChannels();
		unsigned int numUVs = mesh->GetNumUVChannels();


		//if (numColors != 0) {
		//	std::vector<Vec3> colors;
		//	for (Uint j = 0; j < numColors; j++) {
		//		colors.push_back(Vec3(mesh->mColors[j][i].r, mesh->mColors[j][i].g,
		//			mesh->mColors[j][i].b));
		//	}
		//	temp.colors = colors;

		//	colors.clear();
		//}
		//else {
		//	temp.colors.push_back(Vec3(0, 0, 0));
		//}

		//std::cout << numUVs << std::endl;
		if (numUVs) {
			//std::cout << mesh->mTextureCoords[0][i].x << " " << mesh->mTextureCoords[0][i].y << " " << mesh->mTextureCoords[0][i].z << std::endl;
			temp.texCoords = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
	/*		std::vector<Vec2> uvs;

			for (Uint j = 0; j < numUVs; j++) {
				uvs.push_back(Vec2(mesh->mTextureCoords[j][i].x, mesh->mTextureCoords[j][i].y));
			}

			temp.uvs = uvs;

			uvs.clear();
		}
		else {

			temp.uvs.push_back(Vec2(0, 0));*/
		}



		// if(mesh->mColors[) {

		//     tempVec.x = mesh->mColor[i].x;

		// }

		//meshData->vertices.push_back(temp);
		vertices.push_back(temp);
	}


	for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++) {
			indices.push_back(face.mIndices[j]);
		}
	}

	aiMaterial *mat = scene->mMaterials[mesh->mMaterialIndex];
	/*std::cout << mat->Get << std::endl;*/
	/*Mesh *m = new Mesh();
	m->setData(meshData);*/
	std::string indexedMeshName;
	if (sc->indexedMeshes.find(mesh->mName.C_Str()) == sc->indexedMeshes.end()) {
		indexedMeshName = mesh->mName.C_Str();
	}
	else {
		unsigned int i = 1;
		
		while (sc->indexedMeshes.find(std::string(mesh->mName.C_Str()) + std::to_string(i)) != sc->indexedMeshes.end()) {
			++i;
		}
		indexedMeshName = std::string(mesh->mName.C_Str()) + std::to_string(i);
	}
	
	

	sc->indexedMeshes[indexedMeshName].init(vertices, indices);
	std::cout << "Imported mesh name: " << indexedMeshName << std::endl;
	

	
	

	std::string indexedMeshCompName;

	if (sc->indexedMeshComponents.find(mesh->mName.C_Str()) == sc->indexedMeshComponents.end()) {
		indexedMeshCompName = mesh->mName.C_Str();
	}
	else {
		unsigned int i = 1;

		while (sc->indexedMeshComponents.find(std::string(mesh->mName.C_Str()) + std::to_string(i)) != sc->indexedMeshComponents.end()) {
			++i;
		}
		indexedMeshCompName = std::string(mesh->mName.C_Str()) + std::to_string(i);
	}

	sc->indexedMeshComponents[indexedMeshCompName].mesh = &sc->indexedMeshes[indexedMeshName];
	std::cout << "created indexed mesh component named " << indexedMeshCompName << std::endl;

	object->addComponent(0, &sc->materialComponents["mat"]);
	object->addComponent(1, &sc->indexedMeshComponents[indexedMeshCompName]);
	
}
