#include "TemporaryDamagePerRound.hpp"

bool TemporaryDamagePerRound::nextRound(Character& affected)
{
	if (affected.currentHp <= dmgPerRound)
	{
		affected.currentHp = 0;
		affected.isAlive = 0;
	}
	else
	{
		affected.currentHp -= dmgPerRound;
	}
	return elapsed();
}
