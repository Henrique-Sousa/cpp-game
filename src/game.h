#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "character.h"

enum class GameState { play, exit };

class Game
{
  public:
    Game();
    ~Game();

    void run(string title);

    static bool left_btn_pressed;
    static bool right_btn_pressed;

  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int screen_width;
    int screen_height;
    GameState state;
    
    void init(string title);
    void loop();
    void handle_events();
    void update();
    void render();
};

#endif // GAME_H
