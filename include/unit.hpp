#pragma once
#include <cmath>
#include <cstdint>

class Unit
{
  public:
    uint16_t x;
    uint16_t y;

    // Stats
    uint16_t attack;
    uint16_t defense;
    uint16_t speed;
    uint16_t vitality;
    uint16_t power;
    uint16_t resistance;
    uint16_t agility;
    uint16_t stamina;

    // Rechargeable Stats
    uint32_t health;
    uint32_t energy;

    // Level
    uint16_t level;

    uint16_t calculateDamageDealt(const Unit &enemy);
    uint32_t getmaxhealth(void);
    uint32_t getmaxenergy(void);
};