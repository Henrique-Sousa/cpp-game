#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <SDL2/SDL.h>

using namespace std;

enum class MovementState { idle, right, left };

class Character 
{
  public:
    Character(const string, SDL_Point, int, SDL_Renderer*);
    ~Character();

    void draw() const;
    void update();
    SDL_Texture* get_texture();
    void set_position(SDL_Point);
    void move_right();
    void move_left();
    void stop();

  private:
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    int x_velocity;
    MovementState mov_state;
    SDL_Point position;
    const int speed;
};

#endif // CHARACTER_H
