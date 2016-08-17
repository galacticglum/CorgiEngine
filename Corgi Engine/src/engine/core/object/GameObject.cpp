#include "GameObject.h"
#include "Component.h"

GameObject::~GameObject()
{
	for (unsigned int i = 0; i < this->m_Components.size(); i++)
	{
		if (this->m_Components[i])
		{
			delete m_Components[i];
			m_Components[i] = nullptr;
		}
	}

	for (size_t i = 0; i < this->m_Children.size(); i++)
	{
		if (this->m_Children[i])
		{
			delete m_Children[i];
			m_Children[i] = nullptr;
		}
	}
}

GameObject* GameObject::AddChild(GameObject* gameObject)
{
	// If m_Children doesn't contain game object.
	if (std::find(this->m_Children.begin(), this->m_Children.end(), gameObject) == this->m_Children.end())
	{
		this->m_Children.push_back(gameObject);
		gameObject->GetTransform()->SetParent(&this->m_Transform);
		return this;
	}
	// TODO: Logging
	std::cout << "GameObject::AddChild: Could not add child because the child has already been added to the gameobject.\n";
	return this;
}

GameObject* GameObject::AddComponent(Component* component)
{
	this->m_Components.push_back(component);
	component->SetParent(this);
	return this;
}

void GameObject::Update()
{
	for (unsigned int i = 0; i < this->m_Components.size(); i++)
	{
		this->m_Components[i]->Update();
	}

	for (unsigned int i = 0; i < this->m_Children.size(); i++)
	{
		this->m_Children[i]->Update();
	}
}

void GameObject::Render()
{
	for (unsigned int i = 0; i < this->m_Components.size(); i++)
	{
		this->m_Components[i]->Render();
	}

	for (unsigned int i = 0; i < this->m_Children.size(); i++)
	{
		this->m_Children[i]->Render();
	}
}

std::vector<GameObject*> GameObject::GetAllChildren()
{
	std::vector<GameObject*> result;

	for (unsigned int i = 0; i < this->m_Children.size(); i++)
	{
		std::vector<GameObject*> childrenObjects = this->m_Children[i]->GetAllChildren();
		result.insert(result.end(), childrenObjects.begin(), childrenObjects.end());
	}

	result.push_back(this);
	return result;
}