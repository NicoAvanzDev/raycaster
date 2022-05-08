//
// Created by tiger on 5/5/2022.
//

#include "Raycaster.h"

namespace graphics
{
using physics::Vector2f;

void Raycaster::setup()
{
    m_player = engine::Engine::get_drawable<Player>();
    m_grid = engine::Engine::get_drawable<Grid>();
}

void Raycaster::draw(SDL_Renderer* renderer)
{
    auto ray_angle = static_cast<float>(m_player->get_angle() - DR * 30);

    for (int i = 0; i < 60; i++)
    {
        Vector2f ray_start = m_player->get_pos();

        Vector2f ray_dir = {cos(ray_angle), sin(ray_angle)};

        Vector2f ray_unit_step_size = {
            sqrt(1 + (ray_dir.y() * ray_dir.y()) / (ray_dir.x() * ray_dir.x())),
            sqrt(1 + (ray_dir.x() * ray_dir.x()) / (ray_dir.y() * ray_dir.y())),
        };

        ray_unit_step_size.set_x(isinf(ray_unit_step_size.x()) ? 1e30f : ray_unit_step_size.x());
        ray_unit_step_size.set_y(isinf(ray_unit_step_size.y()) ? 1e30f : ray_unit_step_size.y());

        Vector2f map_check = Vector2f(ray_start.x(), ray_start.y());

        Vector2f ray_length;

        Vector2f step;

        if (ray_dir.x() < 0)
        {
            step.set_x(-1);
            float new_ray_x = (ray_start.x() - float(map_check.x())) * ray_unit_step_size.x();
            ray_length.set_x(new_ray_x);
        }
        else
        {
            step.set_x(1);
            float new_ray_x = (float(map_check.x()) + 1 - ray_start.x()) * ray_unit_step_size.x();
            ray_length.set_x(new_ray_x);
        }

        if (ray_dir.y() < 0)
        {
            step.set_y(-1);
            float new_ray_y = (ray_start.y() - float(map_check.y())) * ray_unit_step_size.y();
            ray_length.set_y(new_ray_y);
        }
        else
        {
            step.set_y(1);
            float new_ray_y = (float(map_check.y()) + 1 - ray_start.y()) * ray_unit_step_size.y();
            ray_length.set_y(new_ray_y);
        }

        bool tile_found = false;
        float max_distance = 1000;
        float distance = 0;
        while (!tile_found && distance < max_distance)
        {
            // Walk
            if (ray_length.x() < ray_length.y())
            {
                map_check += Vector2f(step.x(), 0);
                distance = ray_length.x();
                ray_length += Vector2f(ray_unit_step_size.x(), 0);
            }
            else
            {
                map_check += Vector2f(0, step.y());
                distance = ray_length.y();
                ray_length += Vector2f(0, ray_unit_step_size.y());
            }

            Vector2f curr_tile = Vector2f{floor(map_check.x() / m_grid->GRID_CELL_HEIGHT),
                                          floor(map_check.y() / m_grid->GRID_CELL_WIDTH)};

            if ((curr_tile.x() >= 0 && curr_tile.x() < m_grid->ROWS) &&
                (curr_tile.y() >= 0 && curr_tile.y() < m_grid->COLS))
            {
                if (m_grid->map[int(curr_tile.y())][int(curr_tile.x())] == 1)
                    tile_found = true;
            }
        }

        if (tile_found)
        {
            Vector2f intersection;
            intersection = ray_start + ray_dir * distance;
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLineF(renderer, ray_start.x(), ray_start.y(), intersection.x(), intersection.y());
        }

        ray_angle += DR;
    }
}

void Raycaster::fixed_update()
{
}

} // namespace graphics