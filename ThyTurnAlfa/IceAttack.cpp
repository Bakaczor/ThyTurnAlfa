#include "IceAttack.hpp"
#include "Character.hpp"

bool IceAttack::invoke(Character& who, Character& on_whom)
{
	if (!isExecutable(who, on_whom)) return false;

	int dmg = computeDMG(who, on_whom);
	on_whom.hp -= dmg;

	return true;
}
