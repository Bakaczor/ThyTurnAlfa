#include "Wet.hpp"
#include "Burning.hpp"
#include "Cold.hpp"
#include "Frozen.hpp"

bool Wet::addTo(std::vector<std::unique_ptr<Effect>>& applied_effects, int duration, int frozen_duration)
{
	bool apply = true;
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (dynamic_cast<Wet*>(it->get()) || dynamic_cast<Burning*>(it->get()))
		{
			applied_effects.erase(it);
		}
		else if (dynamic_cast<Cold*>(it->get()))
		{
			applied_effects.erase(it);
			applied_effects.emplace_back(std::make_unique<Frozen>(duration));
			apply = false;
		}
	}

	if (apply)
	{
		applied_effects.emplace_back(std::make_unique<Wet>(duration));
	}

	return true;
}