#pragma once
#include "Transform.h"
#include <vector>
#include "Component.h"
#include <map>
#include "CameraAbstract.h"
class SceneObject
{
public:
	SceneObject();
	explicit SceneObject(SceneObject *parent);
	virtual void init(bool includeChildren = true);
	virtual void update(bool includeChildren = true);
	virtual void render(CameraAbstract *cam, bool lightRender = false, bool includeChildren = true);
	virtual void release(bool includeChildren = true);

	Transform getLocalTransform() const
	{
		return m_transform;
	}

	Mat4 getTransformMatrix() const
	{
		if (m_parent)
			return m_parent->getTransformMatrix() * m_transform.getMatrix();

		return m_transform.getMatrix();
	}

	void setTransform(Transform transform)
	{
		m_transform = transform;
		// for ( auto i : m_children ) {
		//     if (i->getActive()) {
		//         Transform trans = i->getTransform();

		//         trans.setTranslation(trans.getTranslation() + m_transform.getTranslation());
		//         // trans.setRotation(trans.getRotation() * m_transform.getRotation());
		//         trans.setScale(trans.getScale() + m_transform.getScale());

		//         i->setTransform(trans);


		//     }
		// }

	}


	std::vector<SceneObject *> getChildren() const
	{
		return m_children;
	}

	/*std::vector<Component *> getComponents() const
	{
		return m_components;
	}*/


	void addChild(SceneObject *child);
	void addComponent(int order, Component *comp);
	void removeComponent(Component *comp);


	bool getActive() const { return m_active; }
	void setActive(bool active)
	{
		m_active = active;
	}


	std::string getName() const { return m_name; }

	void setName(std::string name)
	{
		m_name = name;
	}


private:
	Transform m_transform;

	bool m_active;

	std::map<int, std::vector<Component *>> m_components;
	std::vector<SceneObject *> m_children;
	SceneObject *m_parent;


	std::string m_name;


};