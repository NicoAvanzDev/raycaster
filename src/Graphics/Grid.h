#ifndef RAYCASTER_GRID_H
#define RAYCASTER_GRID_H

#include "../Constants.h"
#include "Drawable.h"
#include <SDL2/SDL.h>

namespace graphics
{

class Grid : public Drawable
{
  public:
    void setup() override;
    void draw(SDL_Renderer *renderer) override;
    void fixed_update() override;
};

} // namespace graphics

#endif // RAYCASTER_GRID_H
