#include "event_delegator.hpp"

bool Event_delegator::register_handler(std::string str, const Event_handler &event_handler)
{
    event_handlers[str] = event_handler;
    return true;
}