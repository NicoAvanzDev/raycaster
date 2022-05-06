#include "Engine.h"

namespace engine
{

using engine::Engine;
using std::shared_ptr, std::vector, graphics::IDrawable;

Engine::Engine()
{
    m_window = nullptr;
    m_renderer = nullptr;
}

vector<shared_ptr<IDrawable>> Engine::m_drawables;

int Engine::initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    m_window = SDL_CreateWindow("Raytracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!m_window)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    return 0;
}

void Engine::event_loop()
{
    SDL_Event event;
    bool is_window_open = true;

    for (auto& drawable : m_drawables)
    {
        drawable->setup();
    }

    Uint64 initial_ticks = SDL_GetTicks64();
    Uint64 ticks = SDL_GetTicks64();
    Uint64 delta_time = 0;

    while (is_window_open)
    {
        initial_ticks = SDL_GetTicks64();

        while (SDL_PollEvent(&event) > 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                is_window_open = false;
                break;
            }
        }

        delta_time += initial_ticks - ticks;

        if (delta_time > (1000 / FRAMERATE))
        {
            for (auto& drawable : m_drawables)
            {
                drawable->fixed_update();
            }

            delta_time = 0;
        }

        ticks = SDL_GetTicks64();

        draw();
    }
}

void Engine::add_drawable(const shared_ptr<IDrawable>& drawable)
{
    m_drawables.push_back(drawable);
}

void Engine::draw()
{
    SDL_SetRenderDrawColor(m_renderer, 142, 142, 142, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_renderer);

    for (auto& m_drawable : m_drawables)
    {
        m_drawable->draw(m_renderer);
    }

    SDL_RenderPresent(m_renderer);
}

Engine::~Engine()
{
    if (m_renderer)
    {
        SDL_DestroyRenderer(m_renderer);
    }
    if (m_window)
    {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

} // namespace engine