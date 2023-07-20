#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "vec2.h"
#include "texture.h"
#include "planet.h"

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;

void init(const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Pianeti", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_SHOWN);
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

int main (int argc, char *argv[]) {
  const int SCREEN_WIDTH = 500;
  const int SCREEN_HEIGHT = 500;
  init(SCREEN_WIDTH, SCREEN_HEIGHT);
  
  std::vector<Planet> planets = {
    Planet(5.9726e24, vec2(0, 1.496e11), vec2(2.978e4, 0)),  // Earth
    Planet(1.989e30, vec2(0, 0), vec2(0, 0))                 // Sun
  };

  return 0;
}
