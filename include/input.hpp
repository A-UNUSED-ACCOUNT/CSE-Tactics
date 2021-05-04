#pragma once

#include <SDL2/SDL.h>
#include <iostream>

class Input
{
  public:
    Input();
    ~Input();
    SDL_Keysym getkeypress();
    SDL_Keysym waitkeypress();
};