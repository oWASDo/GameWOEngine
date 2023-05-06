#include "pch.h"
#include "Vector2.h"
#include <math.h>

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

Vector2 Vector2::operator+(Vector2 b)
{
	Vector2 result = Vector2();
	result.x = x + b.x;
	result.y = y + b.y;
	return result;
}
Vector2 Vector2::operator-(Vector2 b)
{
	Vector2 result = Vector2();
	result.x = x - b.x;
	result.y = y - b.y;
	return result;
}

Vector2 Vector2::operator*(Vector2 b)
{
	Vector2 result = Vector2();
	result.x = x * b.x;
	result.y = y * b.y;
	return result;
}

Vector2 Vector2::operator*(float b)
{
	Vector2 result = Vector2();
	result.x = x * b;
	result.y = y * b;
	return result;
}

Vector2 Vector2::operator/(Vector2 b)
{
	Vector2 result = Vector2();
	result.x = x / b.x;
	result.y = y / b.y;
	return result;
}

Vector2 Vector2::operator/(float b)
{
	Vector2 result = Vector2();
	result.x = x / b;
	result.y = y / b;
	return result;
}

float Vector2::Magnitude()
{
	float result = 0;
	float sqrX = x * x;
	float sqrY = y * y;
	float sqrSum = sqrX + sqrY;
	return sqrtf(sqrSum);

}

Vector2 Vector2::Normalize()
{

	float mag = Magnitude();
	Vector2 me = Vector2(x, y);
	return *this / mag;
}

float Vector2::GetRotation()
{
	return (atan2(y, x) * (180 / 3.14159265358979323846f)) + 90.0f;

}