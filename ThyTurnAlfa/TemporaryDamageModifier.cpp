#include "TemporaryDamageModifier.hpp"

bool TemporaryDamageModifier::nextRound(Character& affected)
{
	if (elapsedRounds == 0)
	{
		affected.wAtk += atkModifier;
		affected.wDef += defModifier;

	}
	if (elapsedRounds == duration)
	{
		remove(affected);
	}
	return elapsed();
}

bool TemporaryDamageModifier::remove(Character& affected)
{
	affected.atk -= atkModifier;
	affected.def -= defModifier;
	return true;
}
