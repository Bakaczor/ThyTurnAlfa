#include "TemporaryDamageModifier.hpp"

bool TemporaryDamageModifier::nextRound(Character& affected)
{
	if (elapsedRounds == 0)
	{
		int modified_w_atk = affected.wAtk + atkModifier;
		if (modified_w_atk < MIN_ATK_VALUE)
		{
			atkModifier = MIN_ATK_VALUE - affected.wAtk;
			affected.wAtk = MIN_ATK_VALUE;
		}
		else
		{
			affected.wAtk = modified_w_atk;
		}
		
		int modified_w_def = affected.wDef + defModifier;
		if (modified_w_def < MIN_DEF_VALUE)
		{
			defModifier = MIN_DEF_VALUE - affected.wDef;
			affected.wDef = 0;
		}
		else
		{
			affected.wDef = modified_w_def;
		}

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
