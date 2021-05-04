#pragma once

#include "event.hpp"
#include "event_handler.hpp"
#include <queue>

class Event_delegator
{
  public:
    bool register_handler(const Event_handler &event_handler);

  private:
    std::queue<Event> event_queue;
    std::queue<Event_handler> event_handlers;
};