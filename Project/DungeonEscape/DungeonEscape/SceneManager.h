#pragma once
#include <string>
#include <vector>
#include "Scene.h"

typedef std::vector<Scene*> SceneList;

class SceneManager
{
private:
	Scene* activeScene;
	SceneList scenes;
public:
	Scene* CreateScene(std::string sceneName);
	Scene* GetScene(std::string sceneName);
	Scene* GetScene(int index);

	SceneList GetAllScenes() {
		return scenes;
	};

	void LoadScene(int level);
	void LoadScene(std::string level);

	Scene* GetLiveScene() {
		return activeScene;
	}
};

