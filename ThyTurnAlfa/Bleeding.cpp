#include "Bleeding.hpp"

bool Bleeding::addTo(std::vector<std::unique_ptr<Effect>>& applied_effects, int duration, int damage_per_round)
{
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (dynamic_cast<Bleeding*>(it->get()))
		{
			applied_effects.erase(it);
		}
	}
	
	applied_effects.emplace_back(std::make_unique<Bleeding>(duration, damage_per_round));

	return true;
}
