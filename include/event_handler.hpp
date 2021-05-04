#include "event.hpp"

template <class T> class Event_handler
{
    virtual bool exec(const T &e) = 0;
};