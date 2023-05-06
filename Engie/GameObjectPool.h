#pragma once
#include "GameObject.h"


#include "Exporter.h"

class ENGIE_EXPORTS GameObjectPool
{
public:
	GameObjectPool();
	~GameObjectPool();


	void AddGameobjectInPool(GameObject* go);

	GameObject* GetGameobjectInPool();

private:
	std::list<GameObject*> gos;

};




