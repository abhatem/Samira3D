#include "SceneLoader.h"
#include "ERROR.h"
#include "Texture.h"
#include "ResourceLoader.h"
using namespace S3D;


/*
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

*/

SceneLoader::SceneLoader(std::string filename)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(filename, aiProcess_GenSmoothNormals | aiProcess_Triangulate | aiProcess_FlipUVs);
	if (!scene->mFlags || !scene->mRootNode)
	{
		//ERROR(1, "The file was not successfully opened.");
	}

	recursiveProcess(scene->mRootNode, scene);
}

void SceneLoader::recursiveProcess(aiNode *node, const aiScene* scene)
{
	for (int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
		processMesh(mesh, scene);
	}

	for (int i = 0; i < node->mNumChildren; i++)
	{
		recursiveProcess(node->mChildren[i], scene);
	}
}

void SceneLoader::processMesh(aiMesh *mesh, const aiScene *scene)
{
	std::vector<Vertex> data;
	std::vector<unsigned int> indicies;
	std::vector<Texture> textures;
	for (int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex temp;
		glm::vec3 tempVec;
		tempVec.x = mesh->mVertices[i].x;
		tempVec.y = mesh->mVertices[i].y;
		tempVec.z = mesh->mVertices[i].z;

		temp.setPosition(tempVec);

		tempVec.x = mesh->mNormals[i].x;
		tempVec.y = mesh->mNormals[i].y;
		tempVec.z = mesh->mNormals[i].z;

		temp.setNormal(tempVec);

		if (mesh->mTangents)
		{
			tempVec.x = mesh->mTangents[i].x;
			tempVec.y = mesh->mTangents[i].y;
			tempVec.z = mesh->mTangents[i].z;

			
		}
		else {
			tempVec.x = 1.0f;
			tempVec.y = tempVec.z = 0.0f;
		}

		temp.setTangent(tempVec);

		if (mesh->mColors[0])
		{
			tempVec.x = mesh->mColors[0][i].r;
			tempVec.y = mesh->mColors[0][i].g;
			tempVec.z = mesh->mColors[0][i].b;
		}
		else
		{
			tempVec.x = tempVec.y = tempVec.z = 0.7;
		}
		temp.setColor(tempVec);

		if (mesh->mTextureCoords[0])
		{
			tempVec.x = mesh->mTextureCoords[0][i].x;
			tempVec.y = mesh->mTextureCoords[0][i].y;
			//tempVec.z = mesh->mTextureCoords[0][i].z;
		}
		else
		{
			tempVec.x = tempVec.y = 0;
		}

		glm::vec2 tempVec2 = glm::vec2(tempVec.x, tempVec.y);

		temp.setTexCoord(tempVec2);

		data.push_back(temp);
	}

	for (int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (int j = 0; j < face.mNumIndices; j++)
		{
			indicies.push_back(face.mIndices[j]);
		}
	}

	aiMaterial *mat = scene->mMaterials[mesh->mMaterialIndex];
	for (int i = 0; i < mat->GetTextureCount(aiTextureType_DIFFUSE); i++)
	{
		aiString str;
		mat->GetTexture(aiTextureType_DIFFUSE, i, &str);
		Texture tempTex(ResourceLoader::loadTexture(str.C_Str()));
		textures.push_back(tempTex);
	}
	Mesh m;
	m.addVertices(data, indicies);
	m_meshes.push_back(new Mesh(m));
}




SceneLoader::~SceneLoader()
{
	for (int i = 0; i < m_meshes.size(); i++)
		delete m_meshes[i];
}


void SceneLoader::draw()
{
	for (int i = 0; i < m_meshes.size(); i++)
		m_meshes[i]->draw();
}