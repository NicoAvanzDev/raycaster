//
// Created by tiger on 4/29/2022.
//

#ifndef RAYTRACER_WINDOW_H
#define RAYTRACER_WINDOW_H

#include <SDL2/SDL.h>
#include <functional>
#include <iostream>

#include "../Constants.h"
#include "../Graphics/Drawable.h"

using std::shared_ptr, std::vector, graphics::Drawable;

namespace engine
{

class Window
{
  private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    vector<shared_ptr<Drawable>> m_drawables;

    void draw();

  public:
    Window();
    ~Window();

    int initialize();
    void event_loop();

    void add_drawable(shared_ptr<Drawable> drawable);
};

} // namespace engine

#endif // RAYTRACER_WINDOW_H
