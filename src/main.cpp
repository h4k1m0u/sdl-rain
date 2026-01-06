#include <SDL2/SDL.h>
#include <iostream>

#include "constants.hpp"
#include "uniform_1d.hpp"
#include "drop.hpp"

using namespace Constants;

/**
 * Rain falling down the window (lines segments drawn in the same random color)
 * https://www.youtube.com/watch?v=KkyIDI6rQJI&t=2s
 */
int main() {
  // SDL2
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    std::cout << "Error init. sdl2: " << SDL_GetError() << '\n';
    std::exit(1);
  }

  SDL_Window* window = SDL_CreateWindow("Rain", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

  // SDL_RENDERER_ACCELERATED: GPU does the rendering instead of CPU (by default)
  // SDL_RENDERER_PRESENTVSYNC: sync'ed with screen refresh rate (otherwise fps > 1000)
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  SDL_Color color = Uniform1D(0, 0xff).get_random_color();

  // create multiple drops
  constexpr size_t N_DROPS = 500;
  std::vector<Drop> drops(N_DROPS);

  for (size_t i = 0; i < N_DROPS; ++i)
    drops[i] = Drop();

  // main loop
  bool quit = false;

  while (!quit) {
    // process events
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
        quit = true;
      }
    }

    // clear window
    SDL_SetRenderDrawColor(renderer, COLOR_BLACK.r, COLOR_BLACK.g, COLOR_BLACK.b, COLOR_BLACK.a);
    SDL_RenderClear(renderer);

    // make drops fall at random speed & draw them
    for (size_t i = 0; i < N_DROPS; ++i) {
      drops[i].fall();
      drops[i].draw(renderer, color);
    }

    SDL_RenderPresent(renderer);
  }

  // free resources
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
