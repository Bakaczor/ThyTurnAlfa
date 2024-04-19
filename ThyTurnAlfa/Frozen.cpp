#include "Frozen.hpp"
#include "Burning.hpp"

bool Frozen::addTo(std::vector<Effect>& applied_effects)
{
	bool apply = true;
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (it->isTypeOf(*this))
		{
			applied_effects.erase(it);
		}
		else if (Burning::isTypeOf(*it))
		{
			applied_effects.erase(it);
			apply = false;
		}
	}
	
	if (apply)
	{
		applied_effects.emplace_back(*this);
	}

	return true;
}

bool Frozen::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_FROZEN) == 0;
}
