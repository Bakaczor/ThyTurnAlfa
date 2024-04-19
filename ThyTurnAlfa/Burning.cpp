#include "Burning.hpp"
#include "Wet.hpp"
#include "Cold.hpp"

bool Burning::addTo(std::vector<Effect>& applied_effects)
{
	bool apply = true;
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (it->isTypeOf(*this) || Cold::isTypeOf(*it))
		{
			applied_effects.erase(it);
		}
		else if (Wet::isTypeOf(*it))
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

bool Burning::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_BURNING) == 0;
}
