#include "input.hpp"
#include "game_instance.hpp"

Input::Input()
{
}

Input::~Input()
{
}

SDL_Keysym Input::waitkeypress()
{
    SDL_Keysym sym;
    sym.sym = 0;
    while (sym.sym == 0)
    {
        sym = getkeypress();
    }
    return sym;
}

SDL_Keysym Input::getkeypress()
{
    SDL_Event event;
    SDL_Keysym sym;
    sym.sym = 0;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            game->shouldexit = true;
            break;
        case SDL_KEYUP:
            break;
        case SDL_KEYDOWN:
            sym = event.key.keysym;
            break;
        case SDL_WINDOWEVENT:
            break;
        default:
            break;
        }
    }
    return sym;
}