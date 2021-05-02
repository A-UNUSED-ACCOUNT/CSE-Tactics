#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include "gridelement.hpp"
#include "graphics.hpp"

#define PIXEL_SIZE 1

class Game
{
public:
    Game();
    ~Game();
    Grid_Element *elements[400];
    SDL_Keysym getkeypress();
    SDL_Keysym waitkeypress();

    bool shouldexit;

    Graphics graphics;

private:
    SDL_Window *w;
    SDL_Renderer *r;
};
