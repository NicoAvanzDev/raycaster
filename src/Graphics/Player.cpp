#include "Player.h"

using graphics::Player;

Player::Player() : Drawable()
{
    m_x = 150;
    m_y = 150;

    m_line = Line(m_x, m_y, 0, 0);
}

void Player::draw(SDL_Renderer *renderer)
{
    // Player draw
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

    const SDL_Rect rect{m_x, m_y, PLAYER_SIZE, PLAYER_SIZE};
    SDL_RenderFillRect(renderer, &rect);

    m_line.draw(renderer);
}

void Player::fixed_update()
{
    handle_keyboard();
    handle_mouse();

    m_line.x1 = m_x + PLAYER_SIZE_HALF;
    m_line.y1 = m_y + PLAYER_SIZE_HALF;
}

void Player::handle_keyboard()
{
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDL_SCANCODE_W])
        m_y -= PLAYER_SPEED;

    if (keystate[SDL_SCANCODE_A])
        m_x -= PLAYER_SPEED;

    if (keystate[SDL_SCANCODE_S])
        m_y += PLAYER_SPEED;

    if (keystate[SDL_SCANCODE_D])
        m_x += PLAYER_SPEED;

    if (m_x < 0)
        m_x = 0;
    if (m_x > WINDOW_WIDTH - PLAYER_SIZE)
        m_x = WINDOW_WIDTH - PLAYER_SIZE;

    if (m_y < 0)
        m_y = 0;
    if (m_y > WINDOW_HEIGHT - PLAYER_SIZE)
        m_y = WINDOW_HEIGHT - PLAYER_SIZE;
}

void Player::handle_mouse()
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    m_line.x2 = x;
    m_line.y2 = y;
}
