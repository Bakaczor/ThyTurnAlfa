#include "Burning.hpp"
#include "Wet.hpp"
#include "Cold.hpp"

bool Burning::addTo(Character& affected, int duration, int damage_per_round)
{
	bool apply = true;

	std::unique_ptr<Burning> ptr;

	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++)
	{
		if (dynamic_cast<Burning*>(it->get()))
		{
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
		else if (dynamic_cast<Wet*>(it->get()))
		{
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
			apply = false;
		}
	}

	if (apply)
	{
		affected.activeEffects.emplace_back(std::make_unique<Burning>(duration, damage_per_round));
	}

	return true;
}
