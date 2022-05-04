#ifndef RAYCASTER_LINE_H
#define RAYCASTER_LINE_H

#include "Drawable.h"

namespace graphics
{
class Line : public Drawable
{

  public:
    Line();
    Line(float x1, float y1, float x2, float y2);

    float x1, y1, x2, y2;

    void draw(SDL_Renderer *renderer) override;
    void setup() override;
    void fixed_update() override;
};
} // namespace graphics

#endif // RAYCASTER_LINE_H