#include "pch.h"
#include "Component.h"
#include <iostream>


Component::Component()
{
	componentName = typeid(*this).name();
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
