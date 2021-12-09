#include <iostream>
#include "game.h"
#include <SDL2/SDL_image.h>

using namespace std;

Character* player;
bool Game::right_btn_pressed = 0;
bool Game::left_btn_pressed = 0;

Game::Game()
  : window {nullptr},
    screen_width {640},
    screen_height {480},
    state {GameState::play}
{
}

Game::~Game()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void Game::init(string title)
{
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

  window = SDL_CreateWindow(
      title.c_str(),
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      screen_width, screen_height, 0);

  if (!window) {
    cout << SDL_GetError() << endl;
    SDL_Quit();
  }

  Uint32 render_flags = SDL_RENDERER_ACCELERATED;
  renderer = SDL_CreateRenderer(window, -1, render_flags);

  SDL_Point origin = {0, 0};
  player = new Character{"../assets/player.png", origin, 3, renderer}; 

  SDL_Rect dest;
  SDL_QueryTexture(player->get_texture(), nullptr, nullptr, &dest.w, &dest.h);
  player->set_position({0, screen_height - dest.h});
}

void Game::run(string title)
{
  init(title);
  loop();
  delete player;
}

void Game::loop()
{
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;
  while (state != GameState::exit)
  {
    frameStart = SDL_GetTicks();

    handle_events();
    update();
    render();

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }
}

void Game::handle_events()
{
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        state = GameState::exit;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.scancode) {
          case SDL_SCANCODE_RIGHT:
            right_btn_pressed = true;
            break;
          case SDL_SCANCODE_LEFT:
            left_btn_pressed = true;
            break;
          default:
            break;
        }
        break;
      case SDL_KEYUP:
        switch (event.key.keysym.scancode) {
          case SDL_SCANCODE_RIGHT:
            right_btn_pressed = false;
            break;
          case SDL_SCANCODE_LEFT:
            left_btn_pressed = false;
            break;
          default:
            break;
        }
        break;
      default:
        break;
    }
  }
  
  if (right_btn_pressed && ! left_btn_pressed) player->move_right();
  else if (! right_btn_pressed && left_btn_pressed) player->move_left();
  else player->stop();
}

void Game::update()
{
  player->update();
}

void Game::render()
{
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);
  player->draw();
  SDL_RenderPresent(renderer);
}
