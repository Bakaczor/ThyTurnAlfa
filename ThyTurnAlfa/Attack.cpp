#include "Attack.hpp"
#include "Character.hpp"

bool Attack::invoke(Character& who, Character& on_whom)
{
	if (!isExecutable(who, on_whom)) return false;

	applyDamage(who, on_whom);

	addEffects(who, on_whom);

	return true;
}

bool Attack::isExecutable(Character& who, Character& on_whom)
{
	return on_whom.hp > 0;
}

void Attack::applyDamage(Character& who, Character& on_whom)
{
	on_whom.hp -= computeDMG(who, on_whom);
}
