#pragma once
#include "GameObject.h"
#include "Crosshair.h"
#include "GameObjectPool.h"

class Player : public GameObject
{
public:

	~Player();

	void Init();

	void Start();


private:

	Crosshair* crosshair;
	GameObjectPool* pool;

};

