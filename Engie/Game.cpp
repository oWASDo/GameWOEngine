
#include "pch.h"

#include "SDL.h"

#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
}


bool Game::InitWindow() {

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 760, SDL_WINDOW_SHOWN);

	if (window != nullptr)
	{
		renderer = SDL_CreateRenderer((SDL_Window*)window, -1, 0);

	}

	if (renderer != nullptr)
	{
		SDL_SetRenderDrawColor((SDL_Renderer*)renderer, 0, 0, 0, 0);

	}
	isRunning = window != nullptr && (SDL_Renderer*)renderer != nullptr;
	return isRunning;
}


void Game::Update() {

}




void Game::Render() {

	SDL_RenderClear((SDL_Renderer*)renderer);

	SDL_RenderPresent((SDL_Renderer*)renderer);

}

void Game::HandleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;

	}
	SDL_UpdateWindowSurface((SDL_Window*)window);
}

void Game::Clean() {
	SDL_DestroyWindow((SDL_Window*)window);
	SDL_DestroyRenderer((SDL_Renderer*)renderer);
	SDL_Quit();
}

void Game::Perform()
{
	while (isRunning)
	{
		HandleEvent();

		Render();

		Update();
	}
}
