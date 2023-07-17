#include "StandardMaterialComp.h"
#include "SceneObject.h"
#include "Globals.h"
void StandardMaterialComp::init(SceneObject * obj)
{
	lamp->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
}

void StandardMaterialComp::update(SceneObject * obj)
{
}

void StandardMaterialComp::render(SceneObject * obj, CameraAbstract* cam, bool lightRender)
{
	if (!lightRender) {
		shader->use();
		diffuseTexture->bind(0);
		shader->updateUniformInt("material.diffuseMap", 0); // GL_TEXTURE0

		specularTexture->bind(1); //GL_TEXTURE1
		shader->updateUniformInt("material.specularMap", 1); //GL_TEXTURE1

		normalTexture->bind(2); //GL_TEXTURE2
		shader->updateUniformInt("material.normalMap", 2); //GL_TEXTURE2

		GLOBAL::lightDepthPass.bindTexture(3);
		shader->updateUniformInt("shadowMap", 3);

		//sh.updateUniformVec3("material.specular", Vec3(0.256777f, 0.137622f, 0.086014f));
		shader->updateUniformFloat("material.shininess", 32.0f);
		shader->updateUniformVec3("light.ambient", Vec3(0.1f, 0.1f, 0.1f));
		shader->updateUniformVec3("light.diffuse", Vec3(1.0f, 1.0f, 1.0f));
		shader->updateUniformVec3("light.specular", Vec3(1.0f, 1.0f, 1.0f));
		shader->updateUniformVec3("light.position", lamp->transform.getTranslation());

		shader->updateUniformMat4("modelMat", obj->getLocalTransform().getMatrix());
		shader->updateUniformMat4("MVP", cam->projection() * cam->view() * obj->getLocalTransform().getMatrix());
		shader->updateUniformVec3("lightColor", lamp->getColor());
		shader->updateUniformVec3("objectColor", Vec3(1.0, 1.0, 0.0));
		shader->updateUniformVec3("lightPosition", lamp->transform.getTranslation());
		shader->updateUniformMat3("normalMat", glm::mat3(glm::transpose(glm::inverse(obj->getLocalTransform().getMatrix()))));
		shader->updateUniformVec3("viewPos", cam->getTransform().getTranslation());
		shader->updateUniformMat4("lightSpaceProjView", lamp->getLightSpaceProjection() * lamp->getLightSpaceView());
		shader->updateUniformVec3("directionalLights[0].direction", Vec3(0.2f, -1.0f, 0.5f));
		shader->updateUniformVec3("directionalLights[0].diffuse", Vec3(1.0f, 1.0f, 1.0f));
		shader->updateUniformVec3("directionalLights[0].specular", Vec3(1.0f, 1.0f, 1.0f));
		shader->updateUniformVec3("directionalLights[0].ambient", Vec3(0.1f, 0.1f, 0.1f));
	}
	else {


		glCullFace(GL_FRONT); // to solve peter panning
		lightDepthShader->use();
		// cam will be our lamp's camera here
		lightDepthShader->updateUniformMat4("MVP_LightSpace", cam->projection() * cam->view() * obj->getLocalTransform().getMatrix());
		glCullFace(GL_BACK);
	}

}

void StandardMaterialComp::release(SceneObject * obj)
{
}
