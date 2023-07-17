#include "DirectionalLight.h"
#include "Globals.h"
DirectionalLight::DirectionalLight()
{
//	lightData.type = Directional;
}

void DirectionalLight::draw()
{
	// render a mesh that represents the light.
}

void DirectionalLight::renderDepthMap(SceneObject & root, const glm::vec3 &lookAt)
{
	// setup the ortho camera 
	ocam.setProjection(-10.0f, 10.0f, 10.0f, -10.0f, -1000.0f, 1000.0f);
	//ocam.setTranslation(lightData.position);
	ocam.lookAt(lookAt);

	// render the whole scene using the ortho camera.
	GLOBAL::lightDepthPass.bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	root.render(&ocam, true, true);
	GLOBAL::lightDepthPass.unbind();

}

void DirectionalLight::bindDepthMap()
{
	GLOBAL::lightDepthPass.bindTexture();
}
