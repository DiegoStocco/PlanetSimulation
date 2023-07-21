#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "vec2.h"
#include "planet.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void init(const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Pianeti", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
}

void quit()
{
  SDL_DestroyRenderer(renderer);
  renderer = NULL;
  SDL_DestroyWindow(window);
  window = NULL;

  SDL_Quit();
}

int main(int argc, char *argv[])
{
  const int SCREEN_WIDTH = 400;
  const int SCREEN_HEIGHT = 400;
  init(SCREEN_WIDTH, SCREEN_HEIGHT);
  
  std::vector<Planet> planets = {
    Planet("Sun", 1.989e30, 20, 0xffdc13ff, vec2(0, 0), vec2(0, 0)),
    Planet("Mercury", 3.301e23, 5, 0xfff5d5ff, vec2(0, 5.791e10), vec2(3.886e4, 0)),
    Planet("Venus", 4.867e24, 7, 0xfff5aaff, vec2(0, 1.082e11), vec2(3.479e4, 0)),
    Planet("Earth", 5.9726e24, 15, 0x67ff67ff, vec2(0, 1.496e11), vec2(2.929e4, 0)),
    Planet("Mars", 6.417e23, 12, 0xff6f6fff, vec2(0, 2.279e11), vec2(2.1972e4, 0))
  };

  const double scale = 1e9;
  const vec2 top_left_corner = vec2(-SCREEN_WIDTH/2.0, -SCREEN_HEIGHT/2.0);
  const double delta_t = 10000;

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  
  bool running = true;
  SDL_Event event;
  while(running)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT) running = false;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for(int i = 0; i < planets.size(); i++)
    {
      planets[i].update(delta_t, &planets);
      planets[i].render(renderer, scale, top_left_corner);
    }
    SDL_RenderPresent(renderer);

  }

  quit();
  return 0;
}
