#include "Character.hpp"
#include "Movement.hpp"

std::string Movement::getCost()
{
    return "0";
}

int Movement::computeDMG(Character& who, Character& on_whom)
{
    float formula_suffix = 1.0f - (float)on_whom.def / UNIT_DEF_VALUE
        * (1.0f + (float)on_whom.wDef / UNIT_DEF_VALUE)
        * (1.0f - wPierce); 
    if (formula_suffix < 0) return 0;

    int dmg = wMove * who.atk * (1.0f + (float)who.wAtk / UNIT_ATK_VALUE) * formula_suffix;
    if (dmg > on_whom.hp) dmg = on_whom.hp;

    return dmg;
}