#include "Engine/Window.h"
#include "Graphics/Grid.h"
#include "Graphics/Player.h"
#include "Graphics/Line.h"

using graphics::Grid, graphics::Player, graphics::Line;

int main(int argc, char **argv)
{
    engine::Window wnd;

    wnd.initialize();

    wnd.add_drawable(std::make_shared<Grid>());
    wnd.add_drawable(std::make_shared<Player>());
    wnd.add_drawable(std::make_shared<Line>());

    wnd.event_loop();

    return 0;
}
