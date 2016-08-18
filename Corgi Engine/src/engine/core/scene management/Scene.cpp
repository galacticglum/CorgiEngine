#include "Scene.h"

void Scene::Load(Game* game)
{
	this->m_Game = game;
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