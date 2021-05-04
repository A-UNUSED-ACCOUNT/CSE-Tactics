#include "event_delegator.hpp"

bool Event_delegator::register_handler(const Event_handler &event_handler)
{
    event_handlers.push(event_handler);
    return true;
}