#include "pch.h"
#include "GameObject.h"
#include <typeinfo>
#include <iostream>
#include "Renderer.h"
#include "Transform.h"
#include "Utils.h"

GameObject::GameObject(const char* nameChar)
{
	name = nameChar;
	rend = nullptr;
	transf = nullptr;
	game = nullptr;
}
GameObject::GameObject()
{
	name = "";
	rend = nullptr;
	transf = nullptr;
	game = nullptr;
	active = true;
}

GameObject::~GameObject()
{
	DELETE_ELEMENTS_IN_A_LIST2(components, Component*);
	CLEAR_LIST(componentsToDelete);

}

void GameObject::AddComponent(Component* newComponent)
{
	if (newComponent->GetTypeName() == "Renderer" || newComponent->GetTypeName() == "Transform")
	{
		return;
	}
	newComponent->SetGameObject(this);
	components.emplace_back(newComponent);

}

void GameObject::RemoveComponent(Component* componentToDelete)
{
	componentsToDelete.emplace_back(componentToDelete);

}

Renderer* GameObject::AddRenderer()
{
	if (rend == nullptr)
	{
		Transform* t = AddTransform();
		transf = t;
		rend = new Renderer();
		components.emplace_back(rend);
		game->AddRenderComponent(rend);
		rend->AddTransform(t);
		rend->SetGameObject(this);

		haveRenderer = true;
	}
	return rend;

}
Transform* GameObject::AddTransform()
{
	if (transf == nullptr)
	{
		transf = new Transform();
		transf->SetGameObject(this);
		components.emplace_back(transf);
	}
	return transf;

}



void GameObject::Update()
{
	for (size_t i = 0; i < components.size(); i++)
	{
		Component* c = nullptr;
		GET_LIST_ELEMENT2(components, Component*, i, c);

		if (c->GetTypeName() == "")
		{
			game->SetIsRunning(false);
			game->SetErroroCode(-5);
			std::cout << "The new Component that you use don't have a filled name" << std::endl;
		}
		if (c->GetActive() && c->componentTypeName != "Renderer")
		{
			c->Update();

		}
	}
}

void GameObject::DeleteComponent()
{
	for (size_t i = 0; i < componentsToDelete.size(); i++)
	{
		for (size_t j = 0; j < components.size(); j++)
		{
			Component* compToDel = nullptr;
			GET_LIST_ELEMENT2(componentsToDelete, Component*, i, compToDel);

			Component* compExist = nullptr;
			GET_LIST_ELEMENT2(components, Component*, j, compExist);


			if (compExist == compExist)
			{
				if (haveRenderer && typeid(*compExist) == typeid(Transform))
				{
					continue;
				}

				if (typeid(*compExist) == typeid(Renderer))
				{
					game->RemoveRenderComponent((Renderer*)compExist);
					haveRenderer = false;
				}

				delete compExist;
				components.remove(compExist);

				CLEAR_LIST(componentsToDelete);

				break;

			}
		}
	}
	CLEAR_LIST(componentsToDelete)

}

void GameObject::DeleteAllComponent()
{
	for (size_t j = 0; j < components.size(); j++)
	{
		Component* component = nullptr;
		GET_LIST_ELEMENT2(components, Component*, j, component);

		if (typeid(*component) == typeid(Renderer))
		{
			game->RemoveRenderComponent((Renderer*)component);
		}
		delete component;

	}
	CLEAR_LIST(components)

}


void GameObject::AddGameOwner(Game* newGame)
{
	game = newGame;
}


template<class T>
T* GameObject::GetComponent()
{
	T* component = dynamic_cast<T*>(GetComponent(typeid(T).name()));
	return component;
}

void GameObject::Start()
{

}

void GameObject::SetActive(bool newActive)
{

	active = newActive;
}

bool GameObject::GetActive()
{
	return active;
}

void GameObject::Init()
{

}

Component* GameObject::GetComponent(const char* name)
{
	for (Component* component : components)
	{
		if (typeid(*component).name() == name)
		{
			return component;
		}
	}
	return nullptr;
}

Texture* GameObject::AddTexture(const char* filePath)
{
	return game->AddTexture(filePath);
}
