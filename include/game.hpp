#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include "gridelement.hpp"

#define PIXEL_SIZE 8

class Game
{
public:
    Game();
    ~Game();
    Grid_Element *elements[400];
    void drawpx(uint16_t x, uint16_t y, const SDL_Color &c);
    void drawelement(Grid_Element &element);
    SDL_Keysym getkeypress();
    SDL_Keysym waitkeypress();
    uint16_t screen_height;
    uint16_t screen_width;
    bool shouldexit;

private:
    SDL_Window *w;
    SDL_Renderer *r;
};
