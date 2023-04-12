#pragma once


#include "SDL.h"
#include "Texture.h"
#include "Transform.h"


class ENGIE_EXPORTS Renderer : public Component
{
public:

	friend class GameObject;

	Renderer();

	~Renderer();

	void Init() override;

	void Start() override;
	
	void Update() override;

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
