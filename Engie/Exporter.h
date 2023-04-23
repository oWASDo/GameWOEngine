#pragma once

#ifdef ENGIE_EXPORTS
#define ENGIE_EXPORTS __declspec(dllexport)
#else
#define ENGIE_EXPORTS __declspec(dllimport)
#endif
