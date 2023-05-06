#include "pch.h"
#include "Transform.h"
#include <math.h>
Transform::Transform()
{
	componentTypeName = "Renderer";
	position = Vector2();
	scale = Vector2(1.0f, 1.0f);
	rotation = 0.0f;
	pivot = Vector2();
	flip = SDL_RendererFlip::SDL_FLIP_NONE;
}

Transform::~Transform()
{
}


Vector2 Transform::GetPosition() {
	return position;
}

float Transform::GetRotation() {
	return rotation;

}

Vector2 Transform::GetScale() {
	return scale;

}

Vector2 Transform::GetPivot() {
	return pivot;

}

SDL_RendererFlip Transform::GetFlip() {
	return flip;

}

Vector2 Transform::GetForward()
{
	float radRot = (rotation - 90.0f) * (3.14159265358979323846f / 180);
	float x = cosf(radRot) * (180 / 3.14159265358979323846f);
	float y = sinf(radRot) * (180 / 3.14159265358979323846f);
	return Vector2(x, y);
}

//Vector2 Transform::GetRight()
//{
//	float radRot = (rotation - 90.0f) * (3.14159265358979323846f / 180);
//	float x = cosf(radRot + 90.0f) * (180 / 3.14159265358979323846f);
//	float y = sinf(radRot + 90.0f) * (180 / 3.14159265358979323846f);
//	return Vector2(x, y);
//}


void Transform::SetPosition(Vector2 pos)
{
	position = pos;
}
void Transform::SetRotation(float rot)
{
	rotation = rot;
}
void Transform::SetScale(Vector2 scal)
{
	scale = scal;
}
void Transform::SetPivot(Vector2 pvt)
{
	pivot = pvt;
}
void Transform::SetFlip(SDL_RendererFlip newFlip)
{
	flip = newFlip;
}