#include "game.hpp"

Game::Game()
{
    for (int x = 0; x < 400; x++)
    {
        elements[x] = new Grid_Element();
    }
}