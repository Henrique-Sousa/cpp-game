#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

enum class State { play, exit };

class Game
{
  public:
    Game();
    ~Game();

    void run();

  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int screen_width;
    int screen_height;
    State state;

    void init();
    void loop();
    void process_input();
    void draw();
};

#endif // GAME_H
