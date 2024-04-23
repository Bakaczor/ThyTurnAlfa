#include "Bleeding.hpp"

bool Bleeding::addTo(Character& affected, int duration, int damage_per_round)
{
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++)
	{
		if (dynamic_cast<Bleeding*>(it->get()))
		{
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
	}
	
	affected.activeEffects.emplace_back(std::make_unique<Bleeding>(duration, damage_per_round));

	return true;
}
