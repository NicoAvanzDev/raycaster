#ifndef RAYCASTER_PLAYER_H
#define RAYCASTER_PLAYER_H

#include "../Constants.h"
#include "Drawable.h"
#include "Line.h"

namespace graphics
{
class Player : public Drawable
{
  private:
    int m_x;
    int m_y;

    Line line;

    static constexpr int PLAYER_SIZE = 20;
    static constexpr int PLAYER_SIZE_HALF = PLAYER_SIZE / 2;
    static constexpr int PLAYER_SPEED = 10;

    void handle_keyboard();    

  public:
    Player();

    void draw(SDL_Renderer *renderer) override;
    void fixed_update() override;
};
} // namespace graphics

#endif