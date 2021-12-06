#include <SDL2/SDL_image.h>

#include "util.h"

SDL_Texture* load_texture(const string texture_path, SDL_Renderer* renderer)
{
  SDL_Surface* surface = IMG_Load(texture_path.c_str());
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  return texture;
}
