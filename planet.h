#ifndef PLANET_H
#define PLANET_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <vector>
#include "vec2.h"
#include "physical_constants.h"

class Planet
{
  public:
    Planet(double massas, vec2 initial_position, vec2 initial_velocity)
    {
      mass = massas;
      position = initial_position;
      velocity = initial_velocity;
    }

    void update(double delta_t, std::vector<Planet> planets)
    {
      acceleration = vec2(0,0);
      vec2 distance;
      for(Planet planet : planets)
      {
        distance = position - planet.position;
        acceleration += ((G * mass * planet.mass) / distance.length_squared()) * unit_vector(distance);
      }
      velocity += acceleration * delta_t;
      position += velocity * delta_t;
    }

    void render(SDL_Renderer* renderer, double scale, vec2 centre = vec2(0,0))
    {
      
    }
  
  public:
    double mass;
    double radius;
    vec2 position;
    vec2 velocity;
    vec2 acceleration;
};

#endif
