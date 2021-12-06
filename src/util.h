#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <SDL2/SDL.h>

using namespace std;

SDL_Texture* load_texture(const string texture_path, SDL_Renderer* renderer);

#endif // UTIL_H
