#ifndef RAYCASTER_ENGINE_H
#define RAYCASTER_ENGINE_H

#include <SDL2/SDL.h>
#include <functional>
#include <iostream>
#include <string>

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
    template <typename T> static shared_ptr<T> get_drawable();
};

template <typename T> shared_ptr<T> Engine::get_drawable()
{
    static_assert(std::is_base_of_v<IDrawable, T>, "Given type does not inherit from IDrawable.");
    for (auto& drawable : m_drawables)
    {
        auto& drawable_type = *drawable;
        if (typeid(drawable_type).name() == typeid(T).name())
            return std::dynamic_pointer_cast<T>(drawable);
    }
    return nullptr;
}

} // namespace engine

#endif // RAYCASTER_ENGINE_H
