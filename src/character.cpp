#include "character.h"
#include "util.h"

#include <SDL2/SDL_image.h>

Character::Character(const string texture_path, 
    SDL_Point pos, SDL_Renderer* rend)
  : renderer {rend},
    position {pos}
{
  texture = load_texture(texture_path, renderer);
}

Character::~Character()
{
  SDL_DestroyTexture(texture);
}

SDL_Texture* Character::get_texture()
{
  return texture;
}

void Character::set_position(SDL_Point pos)
{
  position = pos;
}

void Character::update()
{
  position.x++;
}

void Character::draw() const
{
  SDL_Rect dest;
  SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
  dest.x = position.x;
  dest.y = position.y;
  SDL_RenderCopy(renderer, texture, nullptr, &dest); 
}
