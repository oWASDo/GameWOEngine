#pragma once


#include "Exporter.h"
#include "SDL_image.h"
#include "Vector2.h"

class ENGIE_EXPORTS Texture
{
public:

	Texture(SDL_Texture* newImage, float width, float height);

	~Texture();

	void RenderTexture(SDL_Renderer* renderer);

	SDL_Texture* GetTexture();


	float GetHeight();
	float GetWidth();

private:

	SDL_Texture* image;
	float h;
	float w;

};

