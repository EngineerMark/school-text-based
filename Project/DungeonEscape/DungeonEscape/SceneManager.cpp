#include "pch.h"
#include "SceneManager.h"

Scene* SceneManager::CreateScene(std::string sceneName)
{
	Scene* scene = new Scene();
	scene->SetName(sceneName);

	scenes.push_back(scene);
	return scene;
}

Scene * SceneManager::GetScene(std::string sceneName)
{
	for (size_t i = 0; i < scenes.size(); i++)
	{
		if (scenes[i]->GetName() == sceneName)
			return scenes[i];
	}
	return nullptr;
}

Scene * SceneManager::GetScene(int index)
{
	if (index < scenes.size())
		return scenes[index];
	return nullptr;
}

void SceneManager::LoadScene(int level)
{
	Scene* scene = GetScene(level);

	if (scene == nullptr)
		return;

	activeScene = scene;
}

void SceneManager::LoadScene(std::string level)
{
	size_t i = 0;
	for (size_t i=0;i<scenes.size();i++)
	{
		Scene* scene = scenes[i];
		if (scene->GetName() != level)
			continue;

		LoadScene(i);
		break;
		i++;
	}
}
