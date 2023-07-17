#include "Lamp.h"
#include "PerspectiveCamera.h"
#include "SceneObject.h"
#include "OrthoCamera.h"
#include "Globals.h"

Lamp::Lamp()
{

	std::vector<GLfloat> cubeData = {
		-1.0f,-1.0f,-1.0f, // triangle 1 : begin
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // triangle 1 : end
		1.0f, 1.0f,-1.0f, // triangle 2 : begin
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f, // triangle 2 : end
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};

	m_mesh.init(cubeData);
}

void Lamp::draw()
{
	/*lampShader.use();
	lampShader.updateUniformVec3("color", m_color);*/
	m_mesh.draw();
}

void Lamp::renderDepthMap(SceneObject &root)
{
	ocam.setProjection(-10.0f, 10.0f, 10.0f, -10.0f, -1000.0f, 1000.0f);
	//ocam.setProjection(1.0f, 1.333333f, 0.1f, 1000.0f);
	ocam.setTranslation(transform.getTranslation());
	ocam.lookAt(glm::vec3(0.0f, 0.0f, 0.0f));
	GLOBAL::lightDepthPass.bind();
	//shader.use();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	root.render(&ocam, true, true);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLOBAL::lightDepthPass.unbind();
	/*Camera cam;
	cam.setTranslation()
	m_rp.bind();*/


}

void Lamp::bindDepthMap()
{
	GLOBAL::lightDepthPass.bindTexture();
}
