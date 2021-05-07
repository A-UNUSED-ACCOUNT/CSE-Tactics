#pragma once
#include <cmath>
#include <cstdint>

class Unit
{
  public:
    uint16_t x;
    uint16_t y;
    uint16_t attack;
    uint16_t defense;

    uint16_t calculateDamageDealt(const Unit &enemy);
};