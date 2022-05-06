#include "Line.h"

using graphics::Line;

Line::Line()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
}

Line::Line(float x1, float y1, float x2, float y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

void Line::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
}

void Line::fixed_update()
{
}

void Line::setup()
{
}
