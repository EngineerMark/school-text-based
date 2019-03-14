#pragma once
#include "GameObject.h"
class Scene
{
private:
	std::string name;
	GameObject root;
public:
	void** gameobjects;
	Scene();
	~Scene();

	void AddGameObject(GameObject* go) {
		root.AddComponent(dynamic_cast<Component*>(go));
	}

	void RegisterGameObject(GameObject* go) {
		int size = sizeof(gameobjects) / sizeof(GameObject*);
		gameobjects = (void**)realloc(gameobjects,sizeof(size+1)+sizeof(GameObject*));
		gameobjects[size] = go;
	}

	void RemoveGameObject() {
		
	}

	GameObject* FindGameObject(std::string name) {
		int size = sizeof(gameobjects)/sizeof(GameObject*);
		int deletepos = 0;

		// Delete element
		for (size_t i = 0; i < (size_t)size; i++)
		{
			GameObject* go = (GameObject*)&gameobjects[i];
			if (&go->GetName()!=&name)
				continue;
			deletepos = i;
			delete &gameobjects[i];
			break;
		}

		// Shift remaining elements
		for (size_t i = deletepos; i < size; i++)
		{
			GameObject* temp = (GameObject*)&gameobjects[i];
			gameobjects[i-1] = temp;
			gameobjects[i] = nullptr;
		}

		int newSize = sizeof(gameobjects-1)/sizeof(GameObject*);
		gameobjects = (void**)realloc(gameobjects,newSize);
	}

	void Update(float dt);

	void LoadAllAssets();
	void UnloadAllAssets();

	void Unload();

	std::string GetName() { return name; };
	void SetName(std::string name) { this->name = name; };
};

