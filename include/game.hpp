#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include "gridelement.hpp"
#include "graphics.hpp"
#include "input.hpp"

#define PIXEL_SIZE 1

class Game
{
public:
    Game();
    ~Game();
    Grid_Element *elements[400];

    bool shouldexit;

    Graphics graphics;
    Input input;

private:
    SDL_Window *w;
    SDL_Renderer *r;
};
