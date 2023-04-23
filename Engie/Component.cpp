#pragma once

#include "pch.h"
#include "Component.h"
#include <iostream>
#include "GameObject.h"

Component::Component()
{
	componentTypeName = "";
	int i = 0;
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


void Component::SetGameObject(void* newGameObject)
{
	gameObjectOwner = newGameObject;
}
