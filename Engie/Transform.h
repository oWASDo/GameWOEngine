#pragma once

#include "Component.h"
#include "Vector2.h"
#include "SDL_image.h"

class ENGIE_EXPORTS Transform : public Component
{
public:
	Transform();
	~Transform();

	Vector2 GetPosition();
	float GetRotation();
	Vector2 GetScale();
	Vector2 GetPivot();
	SDL_RendererFlip GetFlip();
	Vector2 GetForward();
	//Vector2 GetRight();

	void SetPosition(Vector2 pos);
	void SetRotation(float rot);
	void SetScale(Vector2 scal);
	void SetPivot(Vector2 pvt);
	void SetFlip(SDL_RendererFlip newFlip);

private:

	Vector2 position;
	float rotation;
	Vector2 scale;
	Vector2 pivot;
	SDL_RendererFlip flip;

};

