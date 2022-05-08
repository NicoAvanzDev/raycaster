#ifndef RAYCASTER_GRID_H
#define RAYCASTER_GRID_H

#include "../Constants.h"
#include "IDrawable.h"
#include <SDL2/SDL.h>

namespace graphics
{
inline constexpr int ROWS = 10;
inline constexpr int COLS = 10;

inline constexpr int GRID_CELL_WIDTH = WINDOW_WIDTH / COLS;
inline constexpr int GRID_CELL_HEIGHT = WINDOW_HEIGHT / ROWS;

const int map[ROWS][COLS] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                             {1, 0, 0, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
                             {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                             {1, 0, 0, 0, 0, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                             {1, 0, 1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

class Grid : public IDrawable
{
  public:
    void setup() override;
    void draw(SDL_Renderer* renderer) override;
    void fixed_update() override;
};

} // namespace graphics

#endif // RAYCASTER_GRID_H
