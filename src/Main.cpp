#include "Engine/Engine.h"
#include "Graphics/Grid.h"
#include "Graphics/Player.h"
#include "Graphics/Raycaster.h"

using graphics::Grid, graphics::Player, graphics::Raycaster;

int main(int argc, char** argv)
{
    engine::Engine wnd;

    wnd.initialize();

    engine::Engine::add_drawable(std::make_shared<Grid>());
    engine::Engine::add_drawable(std::make_shared<Player>());
    engine::Engine::add_drawable(std::make_shared<Raycaster>());

    wnd.event_loop();

    return 0;
}
