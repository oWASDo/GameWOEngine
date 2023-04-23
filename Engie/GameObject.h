#pragma once


#include "Exporter.h"
#include <iostream>
#include <list>

#include "Game.h"
#include "Transform.h"
#include "Renderer.h"


class Game;
class Component;
class Renderer;
class Transform;


class ENGIE_EXPORTS GameObject
{
public:

	GameObject(const char* name);

	~GameObject();

	void AddComponent(Component* newComponent);
	void RemoveComponent(Component* componentToDelete);

	Renderer* AddRenderer();
	Transform* AddTransform();

	void Update();
	void DeleteComponent();
	void DeleteAllComponent();

	void AddGameOwner(Game* newGame);

	template<class T = Component>
	T* GetComponent();

	std::string name;

	Component* GetComponent(const char* name);
private:



	std::list<Component*> components;
	std::list<Component*> componentsToDelete;
	Renderer* rend;
	Transform* transf;
	Game* game;

	bool haveRenderer;

};

#define GET_COMPONENT_AS_POINTER_BY_TYPE(gameobject_,type_) \
dynamic_cast<type_*>(gameobject_->GetComponent(#type_));

#define GET_COMPONENT_AS_POINTER_BY_NAME(gameobject_,type_,name_) \
dynamic_cast<type_*>(gameobject_->GetComponent(name_));
