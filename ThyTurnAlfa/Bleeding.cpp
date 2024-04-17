#include "Bleeding.hpp"

bool Bleeding::nextRound(Character& affected)
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

bool Bleeding::addTo(std::vector<Effect>& applied_effects)
{
	// TODO
	return false;
}

bool Bleeding::remove(Character& affected)
{
	return true;
}
