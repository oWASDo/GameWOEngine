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

	friend class Game;

	GameObject(const char* name);
	GameObject();

	~GameObject();

	virtual void Start();

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

	Texture* AddTexture(const char* filePath);

	Transform* transf;
	Renderer* rend;


	void SetActive(bool newActive);
	bool GetActive();


protected:
	virtual void Init();


private:


	std::list<Component*> components;
	std::list<Component*> componentsToDelete;
	Game* game;

	bool haveRenderer;

	bool active;

};

#define GET_COMPONENT_AS_POINTER_BY_TYPE(gameobject_,type_) \
dynamic_cast<type_*>(gameobject_->GetComponent(#type_));

#define GET_COMPONENT_AS_POINTER_BY_NAME(gameobject_,type_,name_) \
dynamic_cast<type_*>(gameobject_->GetComponent(name_));
