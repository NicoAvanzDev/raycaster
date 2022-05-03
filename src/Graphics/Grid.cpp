#include "Grid.h"

inline constexpr int ROWS = 10;
inline constexpr int COLS = 8;

inline constexpr int GRID_CELL_WIDTH = WINDOW_WIDTH / COLS;
inline constexpr int GRID_CELL_HEIGHT = WINDOW_HEIGHT / ROWS;

using graphics::Grid;

void Grid::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    for (int x = 1; x <= COLS; x++)
    {
        int xPos = x * GRID_CELL_WIDTH;
        SDL_RenderDrawLine(renderer, xPos, 0, xPos, WINDOW_HEIGHT);
    }

    for (int y = 1; y <= ROWS; y++)
    {
        int yPos = y * GRID_CELL_WIDTH;
        SDL_RenderDrawLine(renderer, 0, yPos, WINDOW_WIDTH, yPos);
    }
}

void Grid::fixed_update()
{
}
