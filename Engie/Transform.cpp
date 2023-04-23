#include "pch.h"
#include "Transform.h"

Transform::Transform()
{
	componentTypeName = "Renderer";
	position = Vector2();
	scale = Vector2(1.0f, 1.0f);
	rotation = 0.0f;
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