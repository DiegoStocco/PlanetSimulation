#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "vec2.h"
#include "texture.h"
#include "planet.h"

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;

void init(const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
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
  IMG_Quit();
}

int main () {}
