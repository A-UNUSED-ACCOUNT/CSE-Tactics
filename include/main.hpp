#pragma once

#include "event_handler.hpp"
#include "game.hpp"
#include <string>

class Event_test_handler : public Event_handler
{
  public:
    bool exec(const Event &e)
    {
        std::cout << "Recieved event, events are working correctly" << std::endl;
        return true;
    };
};