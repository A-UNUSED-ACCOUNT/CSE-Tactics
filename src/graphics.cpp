#include "graphics.hpp"
#include "game_instance.hpp"

Graphics::Graphics()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Could not initialise" << std::endl;
        game->shouldexit = true;
    }
}

Graphics::~Graphics()
{
}