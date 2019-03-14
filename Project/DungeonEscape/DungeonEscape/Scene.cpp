#include "pch.h"
#include "Scene.h"


Scene::Scene()
{
	gameobjects = (GameObject**)calloc(0,sizeof(GameObject*));
}


Scene::~Scene()
{
}
