#pragma once

#include "pch.h"
#include "Component.h"
#include <iostream>
#include "GameObject.h"

Component::Component()
{
	componentTypeName = "";
	gameObjectOwner = nullptr;
	active = true;

}

Component::~Component()
{
}

void Component::Init()
{

}

void Component::Start()
{

}

void Component::Update()
{

}


const char* Component::GetTypeName()
{
	return componentTypeName;

}

void Component::SetActive(bool newActive)
{
	active = newActive;
}

bool Component::GetActive()
{
	return active;
}


void Component::SetGameObject(void* newGameObject)
{
	gameObjectOwner = newGameObject;
}


void* Component::GetGameObject()
{
	return gameObjectOwner;
}

