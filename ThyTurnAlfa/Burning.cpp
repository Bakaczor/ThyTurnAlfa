#include "Burning.hpp"
#include "Wet.hpp"
#include "Cold.hpp"

bool Burning::addTo(std::vector<Effect>& applied_effects)
{
	bool apply = true;
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (it->isTypeOf(*this))
		{
			applied_effects.erase(it);
		}
		else if (it->name.compare(EFFECT_NAME_WET) == 0)
		{
			applied_effects.erase(it);
			apply = false;
		} 
		else if (it->name.compare(EFFECT_NAME_COLD) == 0)
		{
			applied_effects.erase(it);
		}
	}

	if (apply)
	{
		applied_effects.emplace_back(*this);
	}

	return true;
}

bool Burning::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_BURNING) == 0;
}
