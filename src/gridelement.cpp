#include "gridelement.hpp"
#include "game_instance.hpp"

Grid_Element::Grid_Element() : texture(nullptr)
{
    texture = IMG_LoadTexture(game->graphics.r, "../");
}

Grid_Element::~Grid_Element()
{
    SDL_DestroyTexture(texture);
}
