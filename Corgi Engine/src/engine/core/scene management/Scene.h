#ifndef _ENGINE_SCENE_H
#define _ENGINE_SCENE_H

#include "../../Engine.h"

class Scene
{
private:
	std::string m_Name;
};

/*

Scene is a root object
	GameObject sprite
		SpriteRenderer component


GameObject root
	GameObject sprite
		SpriteRenderer Component


GameObject -> updated, rendered, etc..

Game : Scene

*/

#endif