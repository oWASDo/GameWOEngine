#pragma once

#include "Exporter.h"


class ENGIE_EXPORTS Component
{
public:
	Component();

	virtual ~Component() = 0;

	//virtual Abstarct() = 0;

	virtual void Init();

	virtual void Start();

	virtual void Update();

	const char* componentName;

private:

};

