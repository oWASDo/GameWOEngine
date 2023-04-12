#include "pch.h"

#include "Loader.h"

#include "SDL_image.h"


SDL_Texture* LoadPng(const char* path, SDL_Renderer* rendere, int* width, int* height)
{

	SDL_Surface* tmpSurface = IMG_Load("./Image/Box.png");

	*width = tmpSurface->w;
	*height = tmpSurface->h;


	const char* CCCC = IMG_GetError();

	SDL_Texture* texture = SDL_CreateTextureFromSurface(rendere, tmpSurface);
	
	SDL_FreeSurface(tmpSurface);

	return texture;

}
