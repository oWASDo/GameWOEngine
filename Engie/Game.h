#pragma once

#ifdef GAMEL_EXPORTS
#define GAMEL_EXPORTS __declspec(dllexport)
#else
#define GAMEL_EXPORTS __declspec(dllimport)
#endif


//#include "SDL.h"

class GAMEL_EXPORTS Game
{
public:
	Game();

	~Game();

	bool InitWindow();

	void Update();

	void Render();

	void HandleEvent();

	void Clean();

	void Perform();

private:

	void* window;

	void* renderer;

	bool isRunning;
};




