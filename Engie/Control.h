#pragma once
#include "SDL_events.h"
#include <list>
#include "Vector2.h"

enum Keys
{
	MOUSE_DOWN = 0,
	MOUSE_UP = 1,
	A = 4,
	B = 5,
	C = 6,
	D = 7,
	E = 8,
	F = 9,
	G = 10,
	H = 11,
	I = 12,
	J = 13,
	K = 14,
	L = 15,
	M = 16,
	N = 17,
	O = 18,
	P = 19,
	Q = 20,
	R = 21,
	S = 22,
	T = 23,
	U = 24,
	V = 25,
	W = 26,
	X = 27,
	Y = 28,
	Z = 29,
	_1 = 30,
	_2 = 31,
	_3 = 32,
	_4 = 33,
	_5 = 34,
	_6 = 35,
	_7 = 36,
	_8 = 37,
	_9 = 38,
	_0 = 39,
	RETURN = 40,
	ESCAPE = 41,
	BACKSPACE = 42,
	TAB = 43,
	SPACE = 44,
	MINUS = 45,
	EQUALS = 46,
	LEFTBRACKET = 47,
	RIGHTBRACKET = 48,
	BACKSLASH = 49,
	//NONUSHASH = 50,
	SEMICOLON = 51,
	APOSTROPHE = 52,
	GRAVE = 53,
	COMMA = 54,
	PERIOD = 55,
	SLASH = 56,
	CAPSLOCK = 57,
	F1 = 58,
	F2 = 59,
	F3 = 60,
	F4 = 61,
	F5 = 62,
	F6 = 63,
	F7 = 64,
	F8 = 65,
	F9 = 66,
	F10 = 67,
	F11 = 68,
	F12 = 69,
	_DELETE = 76,
	RIGHT = 79,
	LEFT = 80,
	DOWN = 81,
	UP = 82,
	KP_ENTER = 88,
	KP_1 = 89,
	KP_2 = 90,
	KP_3 = 91,
	KP_4 = 92,
	KP_5 = 93,
	KP_6 = 94,
	KP_7 = 95,
	KP_8 = 96,
	KP_9 = 97,
	KP_0 = 98,
	F13 = 104,
	F14 = 105,
	F15 = 106,
	F16 = 107,
	F17 = 108,
	F18 = 109,
	F19 = 110,
	F20 = 111,
	F21 = 112,
	F22 = 113,
	F23 = 114,
	F24 = 115,
	KP_TAB = 186,
	LCTRL = 224,
	LSHIFT = 225,
	RCTRL = 228,
	RSHIFT = 229
};

class Control
{
public:

	friend class Game;

	Control();
	~Control();

	static bool GetKeyDown(Keys key);
	static bool GetKeyUp(Keys key);
	static Vector2 GetKeyMousePos(Keys key);
	static Vector2 GetKeyMousePosNormalized(Keys key);
	static Vector2 GetKeyMouseDir(Keys key);


private:
	static std::list<Keys> keyPress;
	static std::list<Keys> keyRelesed;

	static Vector2 mousePos;
	static Vector2 mousePosNormalized;
	static Vector2 mousePosDir;
	static float wheelDir;

	static void PressKeyBind(int keyPressed);
	static void ReleeseKeyBind(int keyPressed);
	static void SetMousePos(float x, float y);
	static void SetMousePosNormalized(float x, float y);
	static void SetMousePosDir(float x, float y);
	static void SetMouseWheel(float x);


	static void FreeKeysLists();

};

