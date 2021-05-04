#include "main.hpp"
#include "game_instance.hpp"

Game *game;

int main(int argc, char *argv[])
{
    uint8_t x = 0;
    uint8_t y = 0;
    SDL_Keysym sym;
    Game *localgame;

    game = new Game();
    localgame = game;

    // Exists so my debugger is forced to show it
    while (!localgame->shouldexit)
    {
        localgame->graphics.drawpx(x, y, {0xff, 0xff, 0xff, 0});
        sym = localgame->input.getkeypress();
    }
    delete game;
    return EXIT_SUCCESS;
}
