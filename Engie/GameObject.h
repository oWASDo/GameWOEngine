#pragma once


#include "Exporter.h"
#include <iostream>
#include <vector>
#include "Component.h"
#include "Transform.h"


#include "Game.h"
#include "Renderer.h"

class Game;
class Renderer;

class ENGIE_EXPORTS GameObject
{
public:

	GameObject(const char* name);

	~GameObject();

	void AddComponent(Component* newComponent);
	Renderer* AddRenderer();
	Transform* AddTransform();

	void Update();

	void AddGameOwner(Game* newGame);

	//template<class T = Component>
	//T* GetComponent();


	template<class T = Component>
	T* GetComponent()
	{
		const char* name = typeid(T).name();

		for (size_t i = 0; i < components.size(); i++)
		{
			if (typeid(T) == typeid(*components.at(i)))
			{
				return dynamic_cast<T*>(components.at(i));
			}

		}

		std::cout << name << std::endl;

		return nullptr;

	}

	std::string name;

private:
	std::vector<Component*> components;
	Renderer* rend;
	Transform* transf;
	Game* game;
};

