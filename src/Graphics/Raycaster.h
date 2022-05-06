//
// Created by tiger on 5/5/2022.
//

#ifndef RAYCASTER_RAYCASTER_H
#define RAYCASTER_RAYCASTER_H

#include <iostream>

#include "../Engine/Engine.h"
#include "../Physics/Vector2f.h"
#include "IDrawable.h"
#include "Player.h"

namespace graphics
{

constexpr int RAYCOUNT = 200;

class Raycaster : public IDrawable
{
  public:
    void setup() override;
    void draw(SDL_Renderer* renderer) override;
    void fixed_update() override;
};

} // namespace graphics

#endif // RAYCASTER_RAYCASTER_H
