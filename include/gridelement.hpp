#pragma once

#include <SDL2/SDL.h>

class Grid_Element
{
public:
    Grid_Element();
    ~Grid_Element();

    SDL_Texture *texture;
};