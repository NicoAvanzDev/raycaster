#include "Player.h"

using graphics::Player;

Player::Player() : Drawable()
{
    m_x = 150;
    m_y = 150;

    m_angle = 90;

    m_dx = cos(m_angle) * TURN_SPEED;
    m_dy = sin(m_angle) * TURN_SPEED;

    m_line = Line(m_x + PLAYER_SIZE_HALF, m_y + PLAYER_SIZE_HALF, m_x + PLAYER_SIZE_HALF + m_dx * RAY_LENGTH,
                  m_y + PLAYER_SIZE_HALF + m_dy * RAY_LENGTH);
}

void Player::draw(SDL_Renderer *renderer)
{
    // Player draw
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    const SDL_FRect rect{m_x, m_y, PLAYER_SIZE, PLAYER_SIZE};
    SDL_RenderFillRectF(renderer, &rect);

    // Ray draw
    m_line.draw(renderer);
}

void Player::fixed_update()
{
    handle_keyboard();

    // Move ray according to player position
    m_line.x1 = m_x + PLAYER_SIZE_HALF;
    m_line.y1 = m_y + PLAYER_SIZE_HALF;

    m_line.x2 = m_line.x1 + m_dx * RAY_LENGTH;
    m_line.y2 = m_line.y1 + m_dy * RAY_LENGTH;
}

void Player::handle_keyboard()
{
    // Handle player movements
    const Uint8 *key_state = SDL_GetKeyboardState(nullptr);

    if (key_state[SDL_SCANCODE_W])
    {
        m_x += m_dx;
        m_y += m_dy;
    }

    if (key_state[SDL_SCANCODE_A])
    {
        m_angle -= .1;

        if (m_angle < 0)
            m_angle += 2 * M_PI;

        m_dx = cos(m_angle) * TURN_SPEED;
        m_dy = sin(m_angle) * TURN_SPEED;
    }

    if (key_state[SDL_SCANCODE_S])
    {
        m_x -= m_dx;
        m_y -= m_dy;
    }

    if (key_state[SDL_SCANCODE_D])
    {
        m_angle += .1;

        if (m_angle > 2 * M_PI)
            m_angle -= 2 * M_PI;

        m_dx = cos(m_angle) * TURN_SPEED;
        m_dy = sin(m_angle) * TURN_SPEED;
    }
}

void Player::setup()
{
}
