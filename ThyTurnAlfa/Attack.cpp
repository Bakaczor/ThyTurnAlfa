#include "Attack.hpp"
#include "Character.hpp"

bool Attack::invoke(Character& who, Character& on_whom)
{
	if (!isExecutable(who, on_whom)) return false;

	applyDamage(who, on_whom);

	addEffects(who, on_whom);

	return true;
}

int Attack::computeDMG(Character& who, Character& on_whom)
{
    float formula_prefix = wMove * who.atk * (1.0f + percent(who.wAtk));
    float formula_suffix = 1.0f - percent(on_whom.def)
        * (1.0f + percent(on_whom.wDef)) * (1.0f - wPierce);
    if (formula_suffix < 0 || formula_prefix < 0) return 0;

    int dmg = formula_prefix * formula_suffix;
    if (dmg > on_whom.hp) dmg = on_whom.hp;

    return dmg;
}

bool Attack::isExecutable(Character& who, Character& on_whom)
{
	return on_whom.hp > 0;
}

void Attack::applyDamage(Character& who, Character& on_whom)
{
	on_whom.hp -= computeDMG(who, on_whom);
}
