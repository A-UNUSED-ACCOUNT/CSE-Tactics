#pragma once

#include "grid_element.hpp"
#include <SDL.h>
#include <iostream>
#include <string>

class Graphics
{
  public:
    Graphics();
    ~Graphics();
    void drawpx(uint16_t x, uint16_t y, const SDL_Color &c);
    void drawelement(Grid_Element &element);
    void drawtext(const std::string &str);

    SDL_Window *w;
    SDL_Renderer *r;

  private:
    uint16_t screen_height;
    uint16_t screen_width;
};