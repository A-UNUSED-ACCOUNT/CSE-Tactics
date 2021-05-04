#pragma once

#include <array>
#include <cstdint>

class Event
{
  public:
    enum class event_code : uint8_t
    {
    };

    event_code code;
};
