#include "Grid.h"

using graphics::Grid;

inline constexpr int ROWS = 10;
inline constexpr int COLS = 10;

inline constexpr int GRID_CELL_WIDTH = WINDOW_WIDTH / COLS;
inline constexpr int GRID_CELL_HEIGHT = WINDOW_HEIGHT / ROWS;

const int map[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void Grid::draw(SDL_Renderer *renderer)
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
