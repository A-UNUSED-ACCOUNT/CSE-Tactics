#pragma once

#include "grid_element.hpp"
#include <SDL2/SDL.h>
#include <iostream>

class Graphics
{
  public:
    Graphics();
    ~Graphics();
    void drawpx(uint16_t x, uint16_t y, const SDL_Color &c);
    void drawelement(Grid_Element &element);

    SDL_Window *w;
    SDL_Renderer *r;

  private:
    uint16_t screen_height;
    uint16_t screen_width;
};