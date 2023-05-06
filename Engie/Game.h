#pragma once

#ifndef GAME
#define GAME


#include "Exporter.h"
#include <list>
#include "SDL.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Transform.h"
#include "Utils.h" 


class GameObject;
class Renderer;

class ENGIE_EXPORTS Game
{
public:
	Game();

	~Game();

	bool InitWindow(const char* gameName, unsigned int width, unsigned int height);

	void Update();

	void Render();

	void HandleEvent();

	void Clean();

	void Time();


	void Perform();

	virtual void Start();

	Texture* AddTexture(const char* path);

	GameObject* AddGameObject(const char* name);
	void AddGameObject(GameObject* newGameObject);

	void RemoveTexture(Texture* texture);

	void RemoveGameObject(GameObject* gameObject);

	SDL_Renderer* GetRenderer();

	void AddRenderComponent(Renderer* newRenderer);

	void RemoveRenderComponent(Renderer* newRenderer);

	void SetIsRunning(bool newIsRunning);
	bool GetIsRunning();

	void SetErroroCode(int newErrorCode);
	int GetErroroCode();

	static float GetDeltaTime() {
		return delta;
	}

	static GameObject* AddGameObjectS(const char* name);
	static void AddGameObjectS(GameObject* newGameObject);
	static void RemoveGameObjectS(GameObject* gameObject);

private:

	static Game* staticGame;

	SDL_Window* window;

	unsigned int ww;
	unsigned int wh;
	const char* name;

	SDL_Renderer* renderer;

	std::list<Texture*> textures;
	std::list<GameObject*> gameObject;
	std::list<GameObject*> gameObjectToRemove;
	std::list<Renderer*> renderers;

	bool isRunning;
	int errorCode;

	void Debug()
	{
		/*
		std::cout << std::endl << "________" << std::endl;
		GameObject* p = nullptr;
		for (size_t i = 0; i < gameObject.size(); i++)
		{
			GameObject* p = nullptr;
			GET_LIST_ELEMENT2(gameObject, GameObject*, i, p);
			if (p != nullptr)
			{
				std::cout << p << std::endl;

			}
			else
			{
				std::cout << "a game object is null" << std::endl;

			}
		}
		std::cout << std::endl << "________" << std::endl;
		*/
	}

	void DeleteGameobject();

	float last_tick_time = 0;
	static float delta;

};


#endif // !GAME

