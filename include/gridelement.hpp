#include <SDL2/SDL.h>

class Grid_Element
{
public:
    Grid_Element();
    SDL_Texture *texture;
    Grid_Element *surroundingelements[6];
};