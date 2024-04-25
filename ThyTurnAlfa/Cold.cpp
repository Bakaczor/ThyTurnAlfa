#include "Cold.hpp"
#include "Wet.hpp"
#include "Burning.hpp"
#include "Frozen.hpp"

bool Cold::addTo(Character& affected, int duration, int frozen_duration)
{
	bool apply = true;
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++)
	{
		if (dynamic_cast<Cold*>((*it).get()))
		{
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
		else if (dynamic_cast<Wet*>((*it).get()))
		{
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
			affected.activeEffects.emplace_back(std::make_unique<Frozen>(frozen_duration));
			apply = false;
		} 
		else if (dynamic_cast<Burning*>((*it).get()))
		{
			apply = false;
		}
	}

	if (apply)
	{
		affected.activeEffects.emplace_back(std::make_unique<Cold>(duration));
	}

	return true;
}
