#include "gridelement.hpp"

Grid_Element::Grid_Element() : texture(nullptr)
{
}

Grid_Element::~Grid_Element()
{
    SDL_DestroyTexture(texture);
}
