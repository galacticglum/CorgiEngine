#ifndef _ENGINE_COMPONENT_H
#define _ENGINE_COMPONENT_H

#include "Transform.h"
#include "GameObject.h"

class Component
{
public:
	Component() : m_Parent(nullptr) {}
	virtual ~Component() {}

	virtual void Update() {}
	virtual void Render() {}


	Transform* GetTransform() { return this->m_Parent->GetTransform(); }
	const Transform& GetTransform() const { return *(this->m_Parent)->GetTransform(); }

	virtual void SetParent(GameObject* gameObject) { this->m_Parent = gameObject; }
private:
	GameObject* m_Parent;
};

#endif