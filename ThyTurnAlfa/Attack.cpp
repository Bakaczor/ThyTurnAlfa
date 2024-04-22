#include "Attack.hpp"

int Attack::computeDMG(Character& who, Character& on_whom)
{
    float formula_prefix = wMove * who.atk * (1.0f + percent(who.wAtk));
    float formula_suffix = 1.0f - percent(on_whom.def)
        * (1.0f + percent(on_whom.wDef)) * (1.0f - wPierce);
    if (formula_suffix < 0 || formula_prefix < 0) return 0;

    int dmg = formula_prefix * formula_suffix;
    if (dmg > on_whom.currentHp) dmg = on_whom.currentHp;

    return dmg;
}

bool Attack::isInvokable(Character& who, Character& on_whom)
{
    return on_whom.currentHp > 0;
}

bool Attack::individualAction(Character& who, Character& on_whom)
{
	on_whom.currentHp -= computeDMG(who, on_whom);
}
