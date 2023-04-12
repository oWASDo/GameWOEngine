#pragma once


#include "Exporter.h"

class ENGIE_EXPORTS Vector2
{
public:
	Vector2();
	Vector2(float newX, float newY);
	~Vector2();

	float GetX();
	float GetY();

	void SetX(float value);
	void SetY(float value);

private:

	float x;
	float y;

};

