#ifndef RAYCASTER_GRID_H
#define RAYCASTER_GRID_H

#include "../Constants.h"
#include "IDrawable.h"
#include <SDL2/SDL.h>

namespace graphics
{

class Grid : public IDrawable
{
  public:
    static constexpr int ROWS = 10;
    static constexpr int COLS = 10;

    static constexpr int GRID_CELL_WIDTH = WINDOW_WIDTH / COLS;
    static constexpr int GRID_CELL_HEIGHT = WINDOW_HEIGHT / ROWS;

    const int map[ROWS][COLS] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                                 {1, 0, 0, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
                                 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                                 {1, 0, 0, 0, 0, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                                 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    void setup() override;
    void draw(SDL_Renderer* renderer) override;
    void fixed_update() override;
};

} // namespace graphics

#endif // RAYCASTER_GRID_H
