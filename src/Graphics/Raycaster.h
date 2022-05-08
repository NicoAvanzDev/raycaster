//
// Created by tiger on 5/5/2022.
//

#ifndef RAYCASTER_RAYCASTER_H
#define RAYCASTER_RAYCASTER_H

#include <iostream>

#include "../Engine/Engine.h"
#include "../Physics/Vector2f.h"
#include "Grid.h"
#include "IDrawable.h"
#include "Player.h"

namespace graphics
{

constexpr int RAYCOUNT = 60;

class Raycaster : public IDrawable
{
  private:
    std::shared_ptr<Player> m_player;
    std::shared_ptr<Grid> m_grid;

  public:
    void setup() override;
    void draw(SDL_Renderer* renderer) override;
    void fixed_update() override;
};

} // namespace graphics

#endif // RAYCASTER_RAYCASTER_H
