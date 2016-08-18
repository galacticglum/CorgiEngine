#include "Scene.h"

void Scene::Load(Window* window, Input* input)
{
	this->m_Window = window;
	this->m_Input = input;

	this->OnLoad();
}

void Scene::Update()
{
	this->OnUpdate();
}

void Scene::Render()
{
	this->OnRender();
}

void Scene::Unload()
{
	this->OnUnload();
}