#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include "gridelement.hpp"

class Graphics
{
public:
    Graphics();
    ~Graphics();
    void drawpx(uint16_t x, uint16_t y, const SDL_Color &c);
    void drawelement(Grid_Element &element);

private:
    SDL_Window *w;
    SDL_Renderer *r;
    uint16_t screen_height;
    uint16_t screen_width;
};