#include "unit.hpp"

uint16_t Unit::calculateDamageDealt(const Unit &enemy)
{
    return static_cast<uint16_t>(round(attack / enemy.defense));
}

uint32_t Unit::getmaxhealth(void)
{
    return vitality * 10;
}
uint32_t Unit::getmaxenergy(void)
{
    return stamina * 5;
}