#ifndef RAYCASTER_PLAYER_H
#define RAYCASTER_PLAYER_H

#include "../Constants.h"
#include "../Physics/Vector2f.h"
#include "Drawable.h"
#include "Line.h"

#define _USE_MATH_DEFINES
#include <cmath>

namespace graphics
{
class Player : public Drawable
{
  private:
    physics::Vector2f m_pos;

    physics::Vector2f m_delta_pos;
    float m_angle;

    Line m_line;

    static constexpr int PLAYER_SIZE = 20;
    static constexpr int PLAYER_SIZE_HALF = PLAYER_SIZE / 2;
    static constexpr int RAY_LENGTH = 20;
    static constexpr int TURN_SPEED = 2;

    void handle_keyboard();

  public:
    Player();

    void setup() override;
    void draw(SDL_Renderer *renderer) override;
    void fixed_update() override;
};
} // namespace graphics

#endif // RAYCASTER_PLAYER_H