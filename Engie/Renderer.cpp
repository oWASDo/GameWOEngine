#include "pch.h"
#include "Renderer.h"
#include <iostream>
#include "Texture.h"


Renderer::Renderer()
{
	componentTypeName = "Renderer";
	transform = nullptr;
	texture = nullptr;
	rend = nullptr;
	UV_Position = Vector2(0.0f, 0.0f);
	UV_Scale = Vector2(1.0f, 1.0f);

}

Renderer::~Renderer()
{

}

void Renderer::Init() {}

void Renderer::Start() {}

void Renderer::Update()
{

	if (texture == nullptr) { return; }

	SDL_Texture* t = texture->GetTexture();

	if (t == nullptr) { return; }

	Vector2 pos = transform->GetPosition();
	Vector2 pivot = transform->GetPivot();
	Vector2 scale = transform->GetScale();
	float rotation = transform->GetRotation();

	float w = texture->GetWidth();
	float h = texture->GetHeight();

	//Size and position
	SDL_Rect size;
	size.x = pos.GetX() + pivot.GetX();
	size.y = pos.GetY() + pivot.GetY();
	size.w = w * scale.GetX();
	size.h = h * scale.GetY();

	//UV to implement
	SDL_Rect position;
	position.x = UV_Position.GetX();
	position.y = UV_Position.GetY();
	position.w = w * UV_Scale.GetX();
	position.h = h * UV_Scale.GetY();

	SDL_Point p;
	p.x = pivot.GetX();
	p.y = pivot.GetY();


	//SDL_RenderCopy(rend, t, &position, &size);
	SDL_RenderCopyEx(rend, t, &position, &size, rotation, &p, transform->GetFlip());


}

void Renderer::AddImage(Texture* newTexture)
{
	texture = newTexture;

}

void Renderer::AddSDLRenderer(SDL_Renderer* newRenderer)
{
	rend = newRenderer;

}
void Renderer::AddTransform(Transform* newT)
{
	transform = newT;
}
