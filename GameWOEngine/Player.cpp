#include "Player.h"

#include "Game.h"
#include "Loader.h"
#include "PlayerController.h"
#include "Bullet.h"

void Player::Init()
{
	crosshair = nullptr;
	pool = nullptr;

	Renderer* renderer = AddRenderer();
	renderer->AddImage(AddTexture("Image/Character.png"));

	crosshair = new Crosshair();

	Game::AddGameObjectS(crosshair);

	PlayerController* pc = new PlayerController();

	pc->AddCrosshair(crosshair);

	AddComponent(pc);

	pool = new GameObjectPool();

	for (size_t i = 0; i < 20; i++)
	{
		pool->AddGameobjectInPool(new Bullet());
	}

	pc->AddPool(pool);

}

void Player::Start() {

}

Player::~Player()
{
	Game::RemoveGameObjectS(crosshair);

}

