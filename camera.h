#ifndef CAMERA_H
#define CAMERA_H

#include "vec2.h"
#include <SDL2/SDL_render.h>

class Camera {
  public:
    Camera(SDL_Renderer* renderer, const int width, const int height, const double scale = 1.0)
    : scale(scale),
      renderer(renderer)
    {
      dimensions = vec2(width, height);
    }

    Camera(SDL_Renderer* renderer, const int width, const int height, vec2 center, const double scale = 1.0)
    : scale(scale),
      renderer(renderer)
    {
      dimensions = vec2(width, height);
      center_to(center);
    }

    void center_to(vec2 point)
    {
      position = point - dimensions/2;
    }

    vec2 world_to_screen(vec2 world_point)
    {
      return vec2(world_point.x()/scale - position.x(),
                  world_point.y()/scale - position.y());
    }

    vec2 screen_to_world(vec2 screen_point)
    {
      return vec2((screen_point.x() + position.x()) * scale,
                  (screen_point.y() + position.y()) * scale);
    }

  public:
    SDL_Renderer* renderer;
    double scale;
    vec2 position;
    vec2 dimensions;
};

#endif
