#include "Grid.h"

namespace graphics
{

void Grid::draw(SDL_Renderer* renderer)
{
    for (int y = 0; y < ROWS; ++y)
    {
        for (int x = 0; x < COLS; ++x)
        {
            int pos_x = x * GRID_CELL_WIDTH;
            int pos_y = y * GRID_CELL_HEIGHT;

            const SDL_Rect rect{pos_x + 1, pos_y + 1, GRID_CELL_WIDTH - 1, GRID_CELL_HEIGHT - 1};
            if (map[y][x] == 1)
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);

            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void Grid::setup()
{
}

void Grid::fixed_update()
{
}

} // namespace graphics