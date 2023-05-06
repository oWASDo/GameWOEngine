#include "PlayerController.h"
#include "Control.h"
#include "GameObject.h"

PlayerController::PlayerController()
{
	componentTypeName = "PlayerController";
	speed = 200.0f;
}

PlayerController::~PlayerController()
{

}

void PlayerController::Update()
{
	Move();
	Aim();
	Shoot();
}

void PlayerController::Start()
{

}



void PlayerController::Move()
{
	Transform* t = static_cast<GameObject*>(gameObjectOwner)->transf;
	Vector2 pos = t->GetPosition();

	if (t == nullptr)
	{
		return;
	}

	if (Control::GetKeyPressed(Keys::D))
	{
		pos.SetX(pos.GetX() + (speed * 1.0f * Game::GetDeltaTime()));
	}
	if (Control::GetKeyPressed(Keys::A))
	{
		pos.SetX(pos.GetX() + (speed * -1.0f * Game::GetDeltaTime()));
	}
	if (Control::GetKeyPressed(Keys::W))
	{
		pos.SetY(pos.GetY() + (speed * -1.0f * Game::GetDeltaTime()));
	}
	if (Control::GetKeyPressed(Keys::S))
	{
		pos.SetY(pos.GetY() + (speed * 1.0f * Game::GetDeltaTime()));
	}
	t->SetPosition(pos);




}


void PlayerController::Aim()
{
	Vector2 pos = Control::GetKeyMousePos();

	crosshair->transf->SetPosition(pos);

}

void PlayerController::Shoot()
{
	if (Control::GetKeyDown(Keys::MOUSE_DOWN))
	{
		GameObject* g = goPool->GetGameobjectInPool();

		Vector2 playerPos = ((GameObject*)gameObjectOwner)->transf->GetPosition();
		if (g != nullptr)
		{
			g->transf->SetPosition(playerPos);

			Vector2 dir = crosshair->transf->GetPosition() - playerPos;

			float f = dir.GetRotation();

			g->transf->SetRotation(dir.GetRotation());


		}
	}
}


void PlayerController::AddCrosshair(Crosshair* ch)
{
	crosshair = ch;
}

void PlayerController::AddPool(GameObjectPool* pool)
{
	goPool = pool;
}