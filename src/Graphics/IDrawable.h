#ifndef RAYCASTER_IDRAWABLE_H
#define RAYCASTER_IDRAWABLE_H

#include <SDL2/SDL.h>

namespace graphics
{
class IDrawable
{
  public:
    virtual void setup() = 0;
    virtual void draw(SDL_Renderer* renderer) = 0;
    virtual void fixed_update() = 0;
};
} // namespace graphics

#endif