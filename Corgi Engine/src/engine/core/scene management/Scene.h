#ifndef _ENGINE_SCENE_H
#define _ENGINE_SCENE_H

#include "../../Engine.h"
#include "../input/Input.h"

class Input;
class Scene
{
friend class SceneManager;
public:
	Scene() {};
	virtual ~Scene() { this->Unload(); }
protected:
	virtual void OnLoad() {}
	virtual void OnUpdate() {}
	virtual void OnRender() {}
	virtual void OnUnload() {}

	Window* GetWindow() { return this->m_Window; }
	Input* GetInput() { return this->m_Input; }
private:
	Input* m_Input;
	Window* m_Window;

	void Load(Window* window, Input* input);
	void Update();
	void Render();
	void Unload();
};

#endif