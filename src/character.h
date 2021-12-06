#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <SDL2/SDL.h>

using namespace std;

class Character 
{
  public:
    Character(const string, SDL_Point, SDL_Renderer*);
    ~Character();

    void draw() const;
    void update();

    SDL_Texture* get_texture();
    void set_position(SDL_Point);

  private:
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    SDL_Point position;
};

#endif // CHARACTER_H
