#include "Crosshair.h"

Crosshair::Crosshair()
{

}

Crosshair::~Crosshair()
{

}

void Crosshair::Start()
{
	Renderer* renderer = AddRenderer();
	renderer->AddImage(AddTexture("Image/Crosshair.png"));

	transf->SetScale(Vector2(0.25f, 0.25f));
	transf->SetPivot(Vector2(-10.0f, -10.0f));

}

