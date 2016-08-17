#ifndef _ENGINE_GAMEOBJECT_H
#define _ENGINE_GAMEOBJECT_H

#include "../../Engine.h"
#include "../../maths/Vector2.h"
#include <vector>

#include "Transform.h"
class Component;

class GameObject
{
public:
	GameObject(const Vector2& position = Vector2::Zero());
	virtual ~GameObject();

	GameObject* AddChild(GameObject* gameObject);
	GameObject* AddComponent(Component* component);

	void Update();
	void Render();

	std::vector<GameObject*> GetAllChildren();

	Transform* GetTransform() { return &(this->m_Transform); }
private:
	std::vector<GameObject*> m_Children;
	std::vector<Component*> m_Components;
	Transform m_Transform;
};

#endif