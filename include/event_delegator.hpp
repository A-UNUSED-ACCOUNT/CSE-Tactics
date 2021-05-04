#pragma once

#include "event.hpp"
#include "event_handler.hpp"
#include <map>
#include <queue>
#include <string>

class Event_delegator
{
  public:
    bool register_handler(std::string str, const Event_handler &event_handler);

  private:
    std::queue<Event> event_queue;
    std::map<std::string, Event_handler> event_handlers;
};