#include "BulletLogic.h"
#include "GameObject.h"

BulletLogic::BulletLogic()
{
	componentTypeName = "BulletLogic";

}

BulletLogic::~BulletLogic()
{
}

void BulletLogic::Update()
{
	Move();
	Time();

}

void BulletLogic::Move()
{
	GameObject* me = ((GameObject*)gameObjectOwner);
	Transform* t = me->transf;

	Vector2 fwd = t->GetForward();
	Vector2 pos = t->GetPosition();
	pos = pos + (fwd * speed * Game::GetDeltaTime());

	t->SetPosition(pos);
}

void BulletLogic::Time()
{
	actualBulletTime += Game::GetDeltaTime();
	std::cout << Game::GetDeltaTime() << std::endl;
	if (actualBulletTime >= maxBulletTime)
	{
		GameObject* me = ((GameObject*)gameObjectOwner);
		me->SetActive(false);
		actualBulletTime = 0.0f;
	}

}
