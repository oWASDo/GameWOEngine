#include "pch.h"
#include "GameObject.h"
#include <typeinfo>
#include <iostream>
#include "Renderer.h"
#include "Transform.h"

GameObject::GameObject(const char* nameChar)
{
	name = nameChar;

}

GameObject::~GameObject()
{

}

void GameObject::AddComponent(Component* newComponent)
{
	if (newComponent->componentName == "Renderer"
		|| newComponent->componentName == "Transform")
	{
		return;
	}

	components.emplace_back(newComponent);

}

Renderer* GameObject::AddRenderer()
{
	if (rend == nullptr)
	{
		Transform* t = AddTransform();
		rend = new Renderer();
		components.emplace_back(rend);
		game->AddRenderComponent(rend);
		rend->AddTransform(t);
	}
	return rend;

}
Transform* GameObject::AddTransform()
{
	if (transf == nullptr)
	{
		transf = new Transform();
		components.emplace_back(transf);
	}
	return transf;

}



void GameObject::Update()
{
	for (size_t i = 0; i < components.size(); i++)
	{
		components.at(i)->Update();
	}
}



void GameObject::AddGameOwner(Game* newGame)
{
	game = newGame;
}

//
//template<class T>
//T* GameObject::GetComponent()
//{
//	std::cout << typeid(T).name() << std::endl;
//
//	return nullptr;
//
//}