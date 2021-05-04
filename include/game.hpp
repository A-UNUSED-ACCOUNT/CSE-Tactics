#pragma once

#include "event_delegator.hpp"
#include "graphics.hpp"
#include "grid_element.hpp"
#include "input.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <nlohmann/json.hpp>

#define PIXEL_SIZE 1

class Game
{
  public:
    Game();
    ~Game();
    bool shouldexit;
    Graphics graphics;
    Input input;
    Event_delegator event_delegator;
    Grid_Element *elements[400];
    nlohmann::json assets;
};
