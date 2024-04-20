#include "OrdinaryAttack.hpp"
#include "Character.hpp"

bool OrdinaryAttack::invoke(Character& who, Character& on_whom)
{
	int dmg = computeDMG(who, on_whom);
	on_whom.hp -= dmg;
	return dmg > 0;
}
