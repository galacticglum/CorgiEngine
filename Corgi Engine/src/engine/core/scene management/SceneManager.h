#ifndef _ENGINE_SCENE_MANAGER_H
#define _ENGINE_SCENE_MANAGER_H

#include "../../Engine.h"
#include "Scene.h"
#include "../../rendering/Window.h"
#include "../input/Input.h"

class Input;
class Window;
class SceneManager
{
public:
	SceneManager(Window* window, Input* input) : m_Window(window), m_Input(input) {}

	void Load(std::string& name, Scene* scene) { Load(name, scene, false, false, 0, 0); }
	void Load(std::string& name, Scene* scene, bool fadeIn, bool fadeOut) { Load(name, scene, fadeIn, fadeOut, 0.8f, 0.8f); }
	void Load(std::string& name, Scene* scene, bool fadeIn, bool fadeOut, float fadeSpeed) { Load(name, scene, fadeIn, fadeOut, fadeSpeed, fadeSpeed); }
	void Load(std::string& name, Scene* scene, bool fadeIn, bool fadeOut, float fadeInSpeed, float fadeOutSpeed);

	void Reload() { Reload(false, false, 0, 0); }
	void Reload(bool fadeIn, bool fadeOut) { Reload(fadeIn, fadeOut, 0.8f, 0.8f); }
	void Reload(bool fadeIn, bool fadeOut, float fadeSpeed) { Reload(fadeIn, fadeOut, fadeSpeed, fadeSpeed); }
	void Reload(bool fadeIn, bool fadeOut, float fadeInSpeed, float fadeOutSpeed);

	void Update() { this->m_ActiveScene->Update(); }
	void Render() { this->m_ActiveScene->Render(); }
	void Destroy();

	const Scene& GetActiveScene() { return *m_ActiveScene; }
	const std::unordered_map<std::string, Scene*> GetAllScenes() { return m_SceneMap; }
private:
	Window* m_Window;
	Input* m_Input;

	Scene* m_ActiveScene;
	std::unordered_map<std::string, Scene*> m_SceneMap;
};

#endif