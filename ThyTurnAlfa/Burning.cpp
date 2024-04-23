#include "Burning.hpp"
#include "Wet.hpp"
#include "Cold.hpp"

bool Burning::addTo(std::vector<std::unique_ptr<Effect>>& applied_effects, int duration, int damage_per_round)
{
	bool apply = true;

	std::unique_ptr<Burning> ptr;

	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (dynamic_cast<Burning*>((*it).get()) || dynamic_cast<Burning*>((*it).get()))
		{
			applied_effects.erase(it);
		}
		else if (dynamic_cast<Wet*>((*it).get()))
		{
			applied_effects.erase(it);
			apply = false;
		}
	}

	if (apply)
	{
		applied_effects.emplace_back(std::make_unique<Burning>(duration, damage_per_round));
	}

	return true;
}
