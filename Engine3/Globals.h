#pragma once
#include "Shader.h"

#include "RenderPass.h"
#include "AssimpImporter.h"
#include "SFML/Window.hpp"
namespace GLOBAL {
	extern RenderPass scenePass;
	extern RenderPass lightDepthPass;
	extern sf::Window window;
	extern int width;
	extern int height;
	extern _AssimpImporter AssimpImporter;
	extern std::vector<GLfloat> triangleData;
	extern std::vector<GLfloat> cubeWithNormalsData;
	extern std::vector<GLfloat> cubeDataWithTexNorm;
	extern std::vector<GLfloat> cubeData;
	extern std::vector<GLfloat> quadData;
	extern std::vector<GLfloat> quadMeshData;
	extern std::vector<GLfloat> quadMeshDataUnscaled;
	extern std::vector<GLfloat> triangleData2;
	extern std::vector<GLuint> indexData;
	extern std::vector<GLfloat> IndexedQuadMeshData;
	extern std::vector<GLuint> quadIndices;

}