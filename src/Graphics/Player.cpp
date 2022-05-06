#include "Player.h"

using graphics::Player;

Player::Player() : IDrawable()
{
    m_pos = physics::Vector2f(150, 150);

    m_angle = 0;

    m_delta_pos.set_x(cos(m_angle) * TURN_SPEED);
    m_delta_pos.set_y(sin(m_angle) * TURN_SPEED);

    m_line = Line(m_pos.x() + PLAYER_SIZE_HALF, m_pos.y() + PLAYER_SIZE_HALF,
                  m_pos.x() + PLAYER_SIZE_HALF + m_delta_pos.x() * RAY_LENGTH,
                  m_pos.y() + PLAYER_SIZE_HALF + m_delta_pos.y() * RAY_LENGTH);
}

void Player::draw(SDL_Renderer* renderer)
{
    // Player draw
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

    const SDL_FRect rect{m_pos.x(), m_pos.y(), PLAYER_SIZE, PLAYER_SIZE};
    SDL_RenderFillRectF(renderer, &rect);

    // Ray draw
    m_line.draw(renderer);
}

void Player::fixed_update()
{
    handle_keyboard();

    // Move ray according to player position
    m_line.x1 = m_pos.x() + PLAYER_SIZE_HALF;
    m_line.y1 = m_pos.y() + PLAYER_SIZE_HALF;

    m_line.x2 = m_line.x1 + m_delta_pos.x() * RAY_LENGTH;
    m_line.y2 = m_line.y1 + m_delta_pos.y() * RAY_LENGTH;
}

void Player::handle_keyboard()
{
    // Handle player movements
    const Uint8* key_state = SDL_GetKeyboardState(nullptr);

    if (key_state[SDL_SCANCODE_W])
    {
        m_pos += m_delta_pos;
    }

    if (key_state[SDL_SCANCODE_A])
    {
        m_angle -= .1;

        if (m_angle < 0)
            m_angle += PI2;

        m_delta_pos.set_x(cos(m_angle) * TURN_SPEED);
        m_delta_pos.set_y(sin(m_angle) * TURN_SPEED);
    }

    if (key_state[SDL_SCANCODE_S])
    {
        m_pos -= m_delta_pos;
    }

    if (key_state[SDL_SCANCODE_D])
    {
        m_angle += .1;

        if (m_angle > PI2)
            m_angle -= PI2;

        m_delta_pos.set_x(cos(m_angle) * TURN_SPEED);
        m_delta_pos.set_y(sin(m_angle) * TURN_SPEED);
    }
}

physics::Vector2f graphics::Player::getPos() const
{
    return m_pos;
}

void Player::setup()
{
}
