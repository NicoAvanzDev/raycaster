#ifndef RAYCASTER_DRAWABLE_H
#define RAYCASTER_DRAWABLE_H

#include <SDL2/SDL.h>

namespace graphics
{
class Drawable
{
  public:
    virtual void setup() = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
    virtual void fixed_update() = 0;
};
} // namespace graphics

#endif