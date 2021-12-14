#include "character.h"
#include "util.h"

#include <SDL2/SDL_image.h>

Character::Character(const string texture_path, 
    SDL_Point pos, int spd, SDL_Renderer* rend)
  : renderer {rend},
    position {pos},
    speed {spd}
{
  texture = load_texture(texture_path, renderer);
}

Character::~Character()
{
  SDL_DestroyTexture(texture);
}

SDL_Texture* Character::get_texture() const
{
  return texture;
}

void Character::set_position(SDL_Point pos)
{
  position = pos;
}

void Character::move_right()
{
  mov_state = MovementState::right;
}

void Character::move_left()
{
  mov_state = MovementState::left;
}

void Character::stop()
{
  mov_state = MovementState::idle;
}

void Character::update()
{
  if (mov_state == MovementState::right) {
    x_velocity = speed;
  }
  if (mov_state == MovementState::left) {
    x_velocity = -speed;
  }
  if (mov_state == MovementState::idle) {
    x_velocity = 0;
  }
  position.x += x_velocity;
}

void Character::draw() const
{
  SDL_Rect dest;
  SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
  dest.x = position.x;
  dest.y = position.y;
  SDL_RenderCopy(renderer, texture, nullptr, &dest); 
}
