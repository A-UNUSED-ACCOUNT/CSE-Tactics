#include "game.hpp"

Game::Game() : shouldexit(false)
{
}

Game::~Game()
{

    SDL_Quit();
}
