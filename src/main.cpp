#include "main.hpp"
#include "game_instance.hpp"

Game *game;

int main(int argc, char *argv[])
{
    uint8_t x = 0;
    uint8_t y = 0;
    SDL_Keysym sym;
    game = new Game();
    while (!game->shouldexit)
    {
        game->graphics.drawpx(x, y, {0xff, 0xff, 0xff, 0});
        sym = game->input.getkeypress();
    }
    delete game;
    return EXIT_SUCCESS;
}
