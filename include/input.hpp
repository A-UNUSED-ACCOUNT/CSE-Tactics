#pragma once

#include <SDL.h>
#include <iostream>

class Input
{
  public:
    Input();
    ~Input();
    SDL_Keysym getkeypress();
    SDL_Keysym waitkeypress();
};