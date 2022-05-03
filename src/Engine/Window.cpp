#include "Window.h"

using engine::Window;

Window::Window()
{
    m_window = nullptr;
    m_renderer = nullptr;
}

int Window::initialize()
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

void Window::event_loop()
{
    SDL_Event event;
    bool is_windowopen = true;

    Uint64 initial_ticks = SDL_GetTicks64();
    Uint64 ticks = SDL_GetTicks64();
    Uint64 delta_time = 0;

    while (is_windowopen)
    {
        initial_ticks = SDL_GetTicks64();

        while (SDL_PollEvent(&event) > 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                is_windowopen = false;
                break;
            }
        }

        delta_time += initial_ticks - ticks;

        if (delta_time > 1000 / FRAMERATE)
        {
            for (auto &drawable : m_drawables)
            {
                drawable->fixed_update();
            }

            delta_time = 0;
        }

        ticks = SDL_GetTicks64();

        draw();
    }
}

void Window::add_drawable(shared_ptr<Drawable> drawable)
{
    m_drawables.push_back(drawable);
}

void Window::draw()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_renderer);
    
    for (int i = 0; i < m_drawables.size(); i++)
    {
        m_drawables[i]->draw(m_renderer);
    }

    SDL_RenderPresent(m_renderer);
}

Window::~Window()
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
