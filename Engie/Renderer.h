#pragma once

#include "SDL.h"
#include "Texture.h"
#include "Transform.h"

class Renderer;
class Transform;

class ENGIE_EXPORTS Renderer : public Component
{
public:

	friend class GameObject;

	Renderer();

	~Renderer();

	void Init();

	void Start();

	void Update();

	void AddImage(Texture* newTexture);

	void AddSDLRenderer(SDL_Renderer* newRenderer);

private:

	void AddTransform(Transform* newT);

	Transform* transform;
	Vector2 UV_Position;
	Vector2 UV_Scale;

	Texture* texture;

	SDL_Renderer* rend;

};

