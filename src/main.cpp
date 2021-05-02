#include "main.hpp"

int main(int argc, char *argv[])
{
    Game *game = new Game();
    while (!game->shouldexit)
    {
        game->drawpx(0, 0, {0xff, 0xff, 0xff, 0});
        game->getkeypress();
    }
    delete game;
    return EXIT_SUCCESS;
}
