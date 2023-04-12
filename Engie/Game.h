#pragma once

#include "Exporter.h"
#include <vector>
#include "SDL.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Transform.h"

class GameObject;

class ENGIE_EXPORTS Game
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

	Texture* AddTexture(const char* path);
	GameObject* AddGameObject(const char* name);

	void RemoveTexture(Texture* texture);
	void RemoveGameObject(GameObject* gameObject);

	SDL_Renderer* GetRenderer();

	void AddRenderComponent(Renderer* newRenderer);

private:

	SDL_Window* window;

	SDL_Renderer* renderer;

	std::vector<Texture*> textures;
	std::vector<GameObject*> gameObject;
	std::vector<Renderer*> renderers;

	bool isRunning;
};



