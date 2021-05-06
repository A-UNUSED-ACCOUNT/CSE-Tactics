#include "grid_element.hpp"
#include "game_instance.hpp"

Grid_Element::Grid_Element()
{
    // texture = IMG_LoadTexture(game->graphics.r, "../lain.png");
    texture = nullptr;
}

Grid_Element::~Grid_Element()
{
    SDL_DestroyTexture(texture);
}
