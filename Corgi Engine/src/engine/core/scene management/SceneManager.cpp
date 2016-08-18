#include "SceneManager.h"

void SceneManager::Load(std::string& name, Scene* scene, bool fadeIn, bool fadeOut, float fadeInSpeed, float fadeOutSpeed)
{
	auto iterator = this->m_SceneMap.find(name);
	if (iterator != this->m_SceneMap.end())
	{
		this->m_ActiveScene = iterator->second;
		this->m_ActiveScene->Load(this->m_Game);
	}

	this->m_SceneMap.insert(std::make_pair(name, scene));
	this->m_ActiveScene = scene;
	this->m_ActiveScene->Load(this->m_Game);
}

void SceneManager::Reload(bool fadeIn, bool fadeOut, float fadeInSpeed, float fadeOutSpeed)
{
	this->m_ActiveScene->Unload();
	this->m_ActiveScene->Load(this->m_Game);
}

void SceneManager::Destroy()
{
	auto scene = this->m_SceneMap.begin();
	if (scene != this->m_SceneMap.end())
	{
		scene->second->Unload();
		delete scene->second;
		this->m_SceneMap.erase(scene);
	}
}


