#include "Bullet.h"
#include "BulletLogic.h"
#include "Renderer.h"


Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	Renderer* renderer = AddRenderer();
	renderer->AddImage(AddTexture("Image/bulletSmall.png"));

	AddComponent(new BulletLogic());

}