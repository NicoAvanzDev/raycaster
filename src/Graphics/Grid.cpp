#include "Grid.h"

inline constexpr int ROWS = 6;
inline constexpr int COLS = 8;

inline constexpr int GRID_CELL_WIDTH = WINDOW_WIDTH / COLS;
inline constexpr int GRID_CELL_HEIGHT = WINDOW_HEIGHT / ROWS;

using graphics::Grid;

void Grid::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);

    for (int x = 1; x <= COLS; x++)
    {
        int xPos = x * GRID_CELL_WIDTH;
        SDL_RenderDrawLine(renderer, xPos, 0, xPos, WINDOW_HEIGHT);
    }

    for (int y = 1; y <= ROWS; y++)
    {
        int yPos = y * GRID_CELL_HEIGHT;
        SDL_RenderDrawLine(renderer, 0, yPos, WINDOW_WIDTH, yPos);
    }
}

void Grid::setup()
{
}

void Grid::fixed_update()
{
}
