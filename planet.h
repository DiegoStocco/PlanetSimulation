#ifndef PLANET_H
#define PLANET_H

#include <SDL2/SDL.h>
#include <vector>
#include "vec2.h"
#include "physical_constants.h"

class Planet
{
  public:
    Planet(vec2 pos, vec2 vel, vec2 acc) {
      position = pos;
      velocity = vel;
      acceleration = acc;
    }

    void update(double delta_t, std::vector<Planet> planets) {
      acceleration = vec2(0,0);
      vec2 distance;
      for(Planet planet : planets) {
        distance = position - planet.position;
        acceleration += ((G * mass * planet.mass) / distance.length_squared()) * unit_vector(distance);
      }
    }
  
  public:
    double mass;
    double radius;
    vec2 position;
    vec2 velocity;
    vec2 acceleration;
};

#endif
