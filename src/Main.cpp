#include "Engine/Window.h"
#include "Graphics/Grid.h"
#include "Graphics/Line.h"
#include "Graphics/Player.h"

using graphics::Grid, graphics::Player, graphics::Line;

int main(int argc, char **argv)
{
    engine::Window wnd;

    wnd.initialize();

    wnd.add_drawable(std::make_shared<Grid>());
    wnd.add_drawable(std::make_shared<Player>());

    wnd.event_loop();

    return 0;
}
