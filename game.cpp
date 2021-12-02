#include <iostream>
#include "game.h"

using namespace std;

Game::Game()
  : window {nullptr},
    screen_width {640},
    screen_height {480},
    state {State::play}
{
}

Game::~Game()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void Game::init()
{
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

  window = SDL_CreateWindow("Game",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      screen_width, screen_height, 0);

  if (!window) {
    cout << SDL_GetError() << endl;
    SDL_Quit();
  }

  Uint32 render_flags = SDL_RENDERER_ACCELERATED;
  renderer = SDL_CreateRenderer(window, -1, render_flags);
}

void Game::run()
{
  init();
  loop();
}

void Game::loop()
{
  while (state != State::exit) {
    process_input();
    draw();
  }
}

void Game::process_input()
{
  SDL_Event event;
  
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        state = State::exit;
        break;
      default:
        break;
    }
  }
}

void Game::draw()
{
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}
