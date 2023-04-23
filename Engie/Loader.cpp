#include "pch.h"

#include "Loader.h"

#include "SDL_image.h"


SDL_Texture* LoadPng(const char* path, SDL_Renderer* rendere, int* width, int* height)
{

	SDL_Surface* tmpSurface = IMG_Load(path);

	if (tmpSurface == nullptr)
	{
		*width = 0;
		*height = 0;
		return nullptr;
	}

	*width = tmpSurface->w;
	*height = tmpSurface->h;


	SDL_Texture* texture = SDL_CreateTextureFromSurface(rendere, tmpSurface);
	
	if (texture == nullptr)
	{
		*width = 0;
		*height = 0;
		SDL_FreeSurface(tmpSurface);
		return nullptr;
	}

	SDL_FreeSurface(tmpSurface);

	return texture;

}
