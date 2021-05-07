#pragma once

#include "SDL.h"
//#include <SDL2/SDL_image.h>

class Grid_Element
{
  public:
    Grid_Element();
    ~Grid_Element();

    SDL_Texture *texture;
};