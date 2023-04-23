#pragma once


#include "Exporter.h"
#include "SDL.h"


extern "C" ENGIE_EXPORTS SDL_Texture * LoadPng(const char* path, SDL_Renderer * rendere, int* width, int* height);