#pragma once

#include "event.hpp"

class Event_handler
{
  public:
    // Execute the function, passing in the event
    bool exec(const Event &e)
    {
        return true;
    };
};
