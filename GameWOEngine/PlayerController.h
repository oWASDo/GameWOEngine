#pragma once
#include "Component.h"
#include "Crosshair.h"
#include "GameObjectPool.h"

class PlayerController : public Component
{
public:
	PlayerController();
	~PlayerController();

	void AddCrosshair(Crosshair* ch);

	void AddPool(GameObjectPool* pool);


private:
	void Update();

	void Start();

	void Move();

	void Aim();

	void Shoot();


	float speed;

	Crosshair* crosshair;

	GameObjectPool* goPool;
};