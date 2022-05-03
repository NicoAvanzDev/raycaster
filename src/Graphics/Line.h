#ifndef RAYCASTER_LINE_H
#define RAYCASTER_LINE_H

#include "Drawable.h"

namespace graphics
{
class Line : public Drawable
{
  public:
    Line();
    Line(int x1, int x2, int y1, int y2);

    int x1, y1, x2, y2;

    void draw(SDL_Renderer *renderer) override;
    void fixed_update() override;
};
} // namespace graphics

#endif // RAYCASTER_LINE_H