#pragma once

#include "Component.h"
#include "Vector2.h"

class ENGIE_EXPORTS Transform : public Component
{
public:
	Transform();
	~Transform();

	void Update() override;

	Vector2 GetPosition();
	float GetRotation();
	Vector2 GetScale();

private:
	Vector2 position;
	float rotation;
	Vector2 scale;

};

