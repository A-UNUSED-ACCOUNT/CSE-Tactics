#include "game.hpp"

Game::Game() : shouldexit(false)
{

    for (int x = 0; x < 400; x++)
    {
        elements[x] = new Grid_Element();
    }
}

Game::~Game()
{
    for (int x = 0; x < 400; x++)
    {
        delete elements[x];
    }
    SDL_Quit();
}

SDL_Keysym Game::waitkeypress()
{
    SDL_Keysym sym;
    sym.sym = 0;
    while (sym.sym == 0)
    {
        sym = getkeypress();
    }
    return sym;
}

SDL_Keysym Game::getkeypress()
{
    SDL_Event event;
    SDL_Keysym sym;
    sym.sym = 0;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            shouldexit = true;
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