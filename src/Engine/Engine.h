#ifndef RAYCASTER_ENGINE_H
#define RAYCASTER_ENGINE_H

#include <SDL2/SDL.h>
#include <functional>
#include <iostream>
#include <typeinfo>

#include "../Constants.h"
#include "../Graphics/IDrawable.h"

namespace engine
{

using std::shared_ptr, std::vector, graphics::IDrawable;

class Engine
{
  private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    static vector<shared_ptr<IDrawable>> m_drawables;

    void draw();

  public:
    Engine();
    ~Engine();

    int initialize();
    void event_loop();

    static void add_drawable(const shared_ptr<IDrawable>& drawable);
};

} // namespace engine

#endif // RAYCASTER_ENGINE_H
