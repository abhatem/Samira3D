
#include "SceneObject.h"
// #include "IO.h"




SceneObject::SceneObject() : m_parent(NULL)
{

	m_active = true;

}

SceneObject::SceneObject(SceneObject *parent) : m_parent(parent)
{

	m_active = true;

	parent->addChild(this);
}


void SceneObject::addChild(SceneObject *child)
{
	m_children.push_back(child);
}

void SceneObject::addComponent(int order, Component *comp)
{
	m_components[order].push_back(comp);
}

void SceneObject::removeComponent(Component *comp) {
	int order=-1, index=-1;
	for (int j = 0; j < m_components.size(); ++j) {
		for (int i = 0; i < m_components[j].size(); ++i) {
			if (comp == m_components[j][i]) {
				order = j;
				index = i;
				break;
			}
			
		}
		if (index > -1) {
			m_components[order].erase(m_components[order].begin() + index);
			break;
		}
	}

	
}


void SceneObject::init(bool includeChildren)
{
	// do my init stuff here
	for (int j = 0; j < m_components.size(); ++j) {
		for (auto i : m_components[j]) {
			i->init(this);
		}

		
	}

	if (includeChildren) {
		for (auto i : m_children) {
			if (i->getActive())
				i->init();
		}
	}
	
}

void SceneObject::update(bool includeChildren)
{
	for (int j = 0; j < m_components.size(); ++j) {
		// do my update stuff here
		for (auto i : m_components[j]) {
			i->update(this);
		}

		
	}

	if (includeChildren) {

		for (auto i : m_children) {
			if (i->getActive())
				i->update();
		}
	}
}

void SceneObject::render(CameraAbstract *cam, bool lightRender, bool includeChildren)
{
	// do my render stuff here
	for (int j = 0; j < m_components.size(); ++j) {
		for (auto i : m_components[j]) {
			i->render(this, cam, lightRender);
		}
	}

	if (includeChildren) {

		for (auto i : m_children) {
			if (i->getActive())
				i->render(cam, lightRender);
		}
	}
}

void SceneObject::release(bool includeChildren)
{
	for (int j = 0; j < m_components.size(); ++j) {
		// do my relese stuff here
		for (auto i : m_components[j]) {
			i->release(this);
		}

		
	}

	if (includeChildren) {

		for (auto i : m_children) {
			if (i->getActive())
				i->release();
		}

	}
}
