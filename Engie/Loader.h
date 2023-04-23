#pragma once


#include "Exporter.h"
#include "SDL.h"


extern "C"  SDL_Texture * LoadPng(const char* path, SDL_Renderer * rendere, int* width, int* height);