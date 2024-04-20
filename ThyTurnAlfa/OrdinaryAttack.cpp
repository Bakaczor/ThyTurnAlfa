#include "OrdinaryAttack.hpp"
#include "Character.hpp"

bool OrdinaryAttack::invoke(Character& who, Character& on_whom)
{
	if (!isExecutable(who, on_whom)) return false;

	int dmg = computeDMG(who, on_whom);
	on_whom.hp -= dmg;
	return true;
}
