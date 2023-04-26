#include "pch.h"
#include "Control.h"

Control::Control()
{
}

Control::~Control()
{
}

bool Control::GetKeyDown(Keys key)
{
	for (Keys k : keyPress)
	{
		if (k == key)
		{
			return true;
		}
	}
	return false;
}

bool Control::GetKeyUp(Keys key)
{
	for (Keys k : keyRelesed)
	{
		if (k == key)
		{
			return true;
		}
	}
	return false;
}

Vector2 Control::GetKeyMousePos()
{
	return mousePos;
}

Vector2 Control::GetKeyMousePosNormalized()
{
	return mousePosNormalized;
}

Vector2 Control::GetKeyMouseDir()
{
	return mousePosDir;
}
float Control::GetKeyWheelDir()
{
	return wheelDir;
}


std::list<Keys> Control::keyPress;
std::list<Keys> Control::keyRelesed;

Vector2 Control::mousePos = Vector2();
Vector2 Control::mousePosNormalized = Vector2();
Vector2 Control::mousePosDir = Vector2();
float Control::wheelDir = 0.0f;

void Control::PressKeyBind(int keyPressed)
{
	//Keys k = (Keys)keyPressed;
	Keys k = static_cast<Keys>(keyPressed);
	keyPress.emplace_back(k);
}

void Control::ReleeseKeyBind(int keyPressed)
{
	//Keys k = (Keys)keyPressed;
	Keys k = static_cast<Keys>(keyPressed);
	keyRelesed.emplace_back(k);
}

void Control::SetMousePos(float x, float y)
{
	mousePos = Vector2(x, y);
}

void Control::SetMousePosNormalized(float x, float y)
{
	mousePosNormalized = Vector2(x, y);

}

void Control::SetMousePosDir(float x, float y)
{
	mousePosDir = Vector2(x, y);
}

void Control::SetMouseWheel(float x)
{
	wheelDir = x;
}



void Control::FreeKeysLists()
{
	keyPress.clear();
	keyRelesed.clear();
	mousePosDir = Vector2(0.0f, 0.0f);
	wheelDir = 0.0f;
}





