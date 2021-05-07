#include "unit.hpp"

uint16_t Unit::calculateDamageDealt(const Unit &enemy)
{
    return static_cast<uint16_t>(round(attack / enemy.defense));
}
