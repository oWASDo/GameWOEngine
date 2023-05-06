#pragma once
#include "Component.h"

class BulletLogic : public Component
{
public:

	BulletLogic();

	~BulletLogic();

	void Update();
	
	void Move();
	void Time();

private:

	float speed = 100.0f;
	float maxBulletTime = 2.0f;
	float actualBulletTime = 0.0f;
};

