#include "Character.hpp"
#include "Movement.hpp"

int Movement::computeDMG(Character& who, Character& on_whom)
{
    float formula_sufix = 1.0f - (float)on_whom.def / UNIT_DEF_VALUE
        * (1.0f + (float)on_whom.wDef / UNIT_DEF_VALUE)
        * (1.0f - wPierce); 
    if (formula_sufix < 0) return 0;

    return wMove * who.atk * (1.0f + (float)who.wAtk / UNIT_ATK_VALUE) * formula_sufix;
}