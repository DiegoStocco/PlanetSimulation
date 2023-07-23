#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "vec2.h"
#include "planet.h"
#include "physical_constants.h"
#include "camera.h"

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
  const int SCREEN_WIDTH = 500;
  const int SCREEN_HEIGHT = 500;
  init(SCREEN_WIDTH, SCREEN_HEIGHT);
  
  std::vector<Planet> planets = {
    Planet("Sun", SUN_MASS, 20, 0xffdc13ff, vec2(0, 0), vec2(0, 0)),
    Planet("Mercury", MERCURY_MASS, 5, 0xfff5d5ff, vec2(0, SUN_MERCURY_MAX_D), vec2(MERCURY_MIN_SPEED, 0)),
    Planet("Venus", VENUS_MASS, 7, 0xfff5aaff, vec2(0, SUN_VENUS_MAX_D), vec2(VENUS_MIN_SPEED, 0)),
    Planet("Earth", EARTH_MASS, 15, 0x67ff67ff, vec2(0, SUN_EARTH_MAX_D), vec2(EARTH_MIN_SPEED, 0)),
    Planet("Moon", MOON_MASS, 3, 0xffffffff, vec2(0, SUN_EARTH_MAX_D + EARTH_MOON_MAX_D), vec2(EARTH_MIN_SPEED + MOON_MIN_SPEED, 0)),
    Planet("Mars", MARS_MASS, 12, 0xff6f6fff, vec2(0, SUN_MARS_MAX_D), vec2(MARS_MIN_SPEED, 0))
  };

  const double SCALE = 1e9;
  const vec2 CENTER = vec2(0, 0);
  Camera cam(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, CENTER, SCALE);

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
      planets[i].render(&cam);
    }
    SDL_RenderPresent(renderer);

  }

  quit();
  return 0;
}
