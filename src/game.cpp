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
