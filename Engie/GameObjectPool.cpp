#include "pch.h"
#include "GameObjectPool.h"

GameObjectPool::GameObjectPool()
{

}

GameObjectPool::~GameObjectPool()
{
	gos.clear();
}

void GameObjectPool::AddGameobjectInPool(GameObject* go)
{
	gos.emplace_back(go);
	Game::AddGameObjectS(go);
	go->SetActive(false);
}

GameObject* GameObjectPool::GetGameobjectInPool()
{
	for (GameObject* go : gos) {
		if (!go->GetActive())
		{
			go->SetActive(true);
			return go;
		}
	}
	return nullptr;
}

