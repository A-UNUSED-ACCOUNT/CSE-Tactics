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

    Event_test_handler test;
    Event event;
    game->event_delegator.register_handler(std::string("Test"), test);
    game->event_delegator.exec(event);
    // Exists so my debugger is forced to show it
    while (!localgame->shouldexit)
    {
        localgame->graphics.drawpx(x, y, {0xff, 0xff, 0xff, 0});
        sym = localgame->input.getkeypress();
    }
    delete game;
    return EXIT_SUCCESS;
}
