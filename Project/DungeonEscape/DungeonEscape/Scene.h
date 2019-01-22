#pragma once
#include "GameObject.h"
class Scene
{
private:
	std::string name;
public:
	std::vector<GameObject*> gameObjects;
	Scene();
	~Scene();

	/*std::vector<GameObject*> GetGameObjects() {
		return gameObjects;
	};*/

	GameObject* AddGameObject(GameObject* go) {
		gameObjects.push_back(go);
		return go;
	}


	void Update(float dt);

	void LoadAllAssets();
	void UnloadAllAssets();

	void Unload();

	std::string GetName() { return name; };
	void SetName(std::string name) { this->name = name; };
};

