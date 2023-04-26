
#include "pch.h"
#include "Game.h"
#include "Loader.h"
#include "Utils.h" 
#include "Control.h"

Game::Game()
{
	errorCode = 0;
	window = nullptr;
	renderer = nullptr;

}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	//delete renderer;
	//renderer = nullptr;

	SDL_DestroyWindow(window);
	//delete window;
	//window = nullptr;

	DELETE_ELEMENTS_IN_A_LIST2(textures, Texture*);

	DELETE_ELEMENTS_IN_A_LIST2(gameObject, GameObject*);

	CLEAR_LIST(renderers);

}

bool Game::InitWindow(const char* gameName, unsigned int width, unsigned int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	ww = width;
	wh = height;
	name = gameName;

	window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ww, wh, SDL_WINDOW_SHOWN);

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

	GameObject* g = nullptr;
	for (size_t i = 0; i < gameObject.size(); i++)
	{

		GET_LIST_ELEMENT2(gameObject, GameObject*, i, g);
		g->Update();

	}

	for (size_t i = 0; i < gameObject.size(); i++)
	{
		GET_LIST_ELEMENT2(gameObject, GameObject*, i, g);
		g->DeleteComponent();


	}

	Debug();
	DeleteGameobject();
	Control::FreeKeysLists();

}

void Game::Render() {

	SDL_RenderClear(renderer);

	Renderer* r = nullptr;
	for (size_t i = 0; i < renderers.size(); i++)
	{
		GET_LIST_ELEMENT2(renderers, Renderer*, i, r);
		r->Update();

	}

	SDL_RenderPresent(renderer);

}

float Game::delta = 0;

void Game::Time() {

	float tick_time = SDL_GetTicks();
	delta = tick_time - last_tick_time;
	last_tick_time = tick_time;

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

	case SDL_KEYDOWN:
		Control::PressKeyBind(event.key.keysym.scancode);
		break;

	case SDL_KEYUP:
		Control::ReleeseKeyBind(event.key.keysym.scancode);
		break;

	case SDL_MOUSEBUTTONDOWN:
		Control::ReleeseKeyBind(0);
		break;

	case SDL_MOUSEBUTTONUP:
		Control::ReleeseKeyBind(1);
		break;

	case SDL_MOUSEWHEEL:
		Control::SetMouseWheel(event.wheel.y);
		break;

	case SDL_MOUSEMOTION:
		Control::SetMousePos(event.motion.x, event.motion.y);
		float xxx = event.motion.x; float yyy = event.motion.y;
		float wxx = ww; float wyy = wh;
		Control::SetMousePosNormalized(xxx / wxx, yyy / wyy);
		Control::SetMousePosDir(event.motion.xrel, event.motion.yrel);
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
	Start();
	while (isRunning)
	{
		Time();

		HandleEvent();

		Update();

		Render();

	}
}

void Game::Start() {

	for (GameObject* g : gameObject)
	{
		g->Start();
	}
}

Texture* Game::AddTexture(const char* path)
{
	int* w = new int();
	int* h = new int();
	SDL_Texture* image = LoadPng(path, renderer, w, h);

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

	AddGameObject(newGameObject);

	return newGameObject;
}

void Game::AddGameObject(GameObject* newGameObject)
{
	newGameObject->AddGameOwner(this);

	gameObject.emplace_back(newGameObject);

	newGameObject->Init();

}

void Game::RemoveTexture(Texture* texture)
{

}

void Game::RemoveGameObject(GameObject* gameObject)
{
	gameObjectToRemove.push_back(gameObject);
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

void Game::RemoveRenderComponent(Renderer* newRenderer)
{
	for (size_t i = 0; i < renderers.size(); i++)
	{
		//if (renderers[i] = newRenderer)

		Renderer* r = nullptr;

		GET_LIST_ELEMENT2(renderers, Renderer*, i, r);
		//Utils::GetListElement(renderers, i);
		if (r = newRenderer)
		{
			renderers.remove(r);
			break;

		}
	}
}

void Game::DeleteGameobject()
{
	GameObject* objToRemove = nullptr;
	for (size_t i = 0; i < gameObjectToRemove.size(); i++)
	{
		//gameObjectToRemove.at(i)->DeleteAllComponent();
		GET_LIST_ELEMENT2(gameObjectToRemove, GameObject*, i, objToRemove);




		//GameObject* objToRemove = Utils::GetListElement(gameObjectToRemove, i);
		objToRemove->DeleteAllComponent();

		GameObject* actualObj = nullptr;
		//Utils::GetListElement(gameObject, j);

		for (size_t j = 0; j < gameObject.size(); j++)
		{
			GET_LIST_ELEMENT2(gameObject, GameObject*, j, actualObj);
			if (actualObj = objToRemove)
			{
				gameObject.remove(actualObj);
				delete actualObj;
				//gameObject.erase(gameObject.begin() + j);

				CLEAR_LIST(gameObjectToRemove);

				break;

			}
		}
	}
	CLEAR_LIST(gameObjectToRemove)


}

void Game::SetIsRunning(bool newIsRunning)
{
	isRunning = newIsRunning;
}
bool Game::GetIsRunning()
{
	return isRunning;
}

void Game::SetErroroCode(int newErrorCode)
{
	errorCode = newErrorCode;
}
int Game::GetErroroCode()
{
	return errorCode;
}
//
//SDL_Texture* Game::LoadImg(const char* path, SDL_Renderer* rendere, int* width, int* height) {
//
//	SDL_Surface* tmpSurface = IMG_Load("./Image/Box.png");
//
//	*width = tmpSurface->w;
//	*height = tmpSurface->h;
//
//
//	const char* CCCC = IMG_GetError();
//
//	SDL_Texture* texture = SDL_CreateTextureFromSurface(rendere, tmpSurface);
//
//	SDL_FreeSurface(tmpSurface);
//
//	return texture;
//}