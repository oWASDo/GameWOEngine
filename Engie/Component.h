#pragma once

#include "Exporter.h"

class ENGIE_EXPORTS Component
{
public:

	friend class GameObject;

	Component();

	virtual ~Component() = 0;

	virtual void Init();

	virtual void Start();

	virtual void Update();

	const char* GetTypeName();

	void SetActive(bool newActive);

	bool GetActive();

	void* GetGameObject();
	
protected:

	const char* componentTypeName;

	void* gameObjectOwner;

	void SetGameObject(void* newGameObject);

private:

	bool active;

};

#define GET_GAMEOBJECT_OWNER 1