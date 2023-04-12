#include "pch.h"
#include "Vector2.h"


Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float newX, float newY)
{
	x = newX;
	y = newY;
}

Vector2::~Vector2()
{

}

float Vector2::GetX() {
	return x;
}

float Vector2::GetY() {
	return y;

}

void Vector2::SetX(float value) {
	x = value;

}
void Vector2::SetY(float value) {
	y = value;

}