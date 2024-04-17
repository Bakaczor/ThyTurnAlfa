#include "Boost.hpp"

bool Boost::nextRound(Character& affected)
{
	if (elapsedRounds == 0) 
	{
		affected.wAtk += atkBoost;
		affected.wDef += defBoost;
	} 
	if (elapsedRounds == duration)
	{
		remove(affected);
	}
	return elapsed();
}

bool Boost::addTo(std::vector<Effect>& applied_effects)
{
	// TODO
	return false;
}

bool Boost::remove(Character& affected)
{
	affected.atk -= atkBoost;
	affected.def -= defBoost;
	return true;
}
