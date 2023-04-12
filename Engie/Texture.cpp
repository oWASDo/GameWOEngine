#include "pch.h"
#include "Texture.h"

Texture::Texture(SDL_Texture* newImage, const float width, const float height)
{
	image = newImage;
	h = height;
	w = width;
}

Texture::~Texture()
{

}

void Texture::RenderTexture(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, image, nullptr, nullptr);

}

SDL_Texture* Texture::GetTexture()
{
	return image;
}

float Texture::GetHeight() {
	return h;
}

float Texture::GetWidth() {
	return w;
}