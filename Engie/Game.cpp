
#include "pch.h"
#include "Game.h"
#include "Loader.h"

Game::Game()
{

}

Game::~Game()
{

}


bool Game::InitWindow()
{

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 760, SDL_WINDOW_SHOWN);

	if (window != nullptr)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);

	}

	if (renderer != nullptr)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	}
	isRunning = window != nullptr && renderer != nullptr;
	return isRunning;

}


void Game::Update() {

	for (size_t i = 0; i < gameObject.size(); i++)
	{
		gameObject.at(i)->Update();

	}
}


void Game::Render() {

	SDL_RenderClear(renderer);

	for (size_t i = 0; i < renderers.size(); i++)
	{
		renderers.at(i)->Update();
	}

	SDL_RenderPresent(renderer);

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
	SDL_UpdateWindowSurface(window);

}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
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

Texture* Game::AddTexture(const char* path)
{
	int* w = new int();
	int* h = new int();
	SDL_Texture* image = LoadPng(path, renderer, w, h);
	//textures.emplace_back(image);
	if (image != nullptr)
	{
		Texture* texture = new Texture(image, *w, *h);
		textures.emplace_back(texture);
		delete w;
		delete h;
		return texture;
	}
	delete w;
	delete h;
	return nullptr;
}

GameObject* Game::AddGameObject(const char* name)
{
	GameObject* newGameObject = new GameObject(name);

	newGameObject->AddGameOwner(this);

	gameObject.emplace_back(newGameObject);



	return newGameObject;
}

void Game::RemoveTexture(Texture* texture)
{

}


void Game::RemoveGameObject(GameObject* gameObject)
{

}

SDL_Renderer* Game::GetRenderer()
{
	return renderer;
}

void Game::AddRenderComponent(Renderer* newRenderer)
{
	newRenderer->AddSDLRenderer(renderer);
	renderers.emplace_back(newRenderer);
}

