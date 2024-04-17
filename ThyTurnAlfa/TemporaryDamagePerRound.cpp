#include "TemporaryDamagePerRound.hpp"

bool TemporaryDamagePerRound::nextRound(Character& affected)
{
	if (affected.hp <= dmgPerRound)
	{
		affected.hp = 0;
		affected.isAlive = 0;
	}
	else
	{
		affected.hp -= dmgPerRound;
	}
	return elapsed();
}

bool TemporaryDamagePerRound::remove(Character& affected)
{
	return true;
}
