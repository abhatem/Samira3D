#pragma once

#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Mesh.h"

namespace S3D {
	class SceneLoader
	{
	public:
		SceneLoader(std::string filename);
		~SceneLoader();
		void draw();
		std::vector<Mesh*>& getMeshes() { return m_meshes; }

	private:
		std::vector<Mesh*> m_meshes;
		void recursiveProcess(aiNode *node, const aiScene *scene);
		void processMesh(aiMesh *mesh, const aiScene *scene);
	};
}