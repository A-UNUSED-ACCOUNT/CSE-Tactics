#include "event_delegator.hpp"

bool Event_delegator::register_handler(std::string str, const Event_handler &event_handler)
{
    if (event_handlers.count(str) == 0)
    {
        event_handlers[str] = event_handler;
        return true;
    }
    else
    {
        return false;
    }
}

bool Event_delegator::exec(const Event &event)
{
    for (auto &x : event_handlers)
    {
        x.second.exec(event);
    }
    return true;
}
