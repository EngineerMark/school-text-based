#pragma once
#include "GameObject.h"
class Scene
{
private:
	std::string name;
	GameObject root;
public:
	std::vector<GameObject*> gameObjects;
	Scene();
	~Scene();

	/*std::vector<GameObject*> GetGameObjects() {
		return gameObjects;
	};*/

	void AddGameObject(GameObject* go) {
		root.AddComponent(dynamic_cast<Component*>(go));
	}


	void Update(float dt);

	void LoadAllAssets();
	void UnloadAllAssets();

	void Unload();

	std::string GetName() { return name; };
	void SetName(std::string name) { this->name = name; };
};

