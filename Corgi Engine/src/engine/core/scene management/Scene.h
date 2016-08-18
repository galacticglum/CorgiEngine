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

	Game* GetGame() { return this->m_Game; }
private:
	Game* m_Game;

	void Load(Game* game);
	void Update();
	void Render();
	void Unload();
};

#endif