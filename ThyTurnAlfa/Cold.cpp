#include "Cold.hpp"
#include "Wet.hpp"
#include "Burning.hpp"
#include "Frozen.hpp"

bool Cold::addTo(std::vector<Effect>& applied_effects)
{
	bool apply = true;
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (it->isTypeOf(*this))
		{
			applied_effects.erase(it);
		}
		else if (Wet::isTypeOf(*it))
		{
			applied_effects.erase(it);
			Frozen frozen_effect = Frozen(this->duration);
			applied_effects.emplace_back(frozen_effect);
			apply = false;
		} 
		else if (Burning::isTypeOf(*it))
		{
			apply = false;
		}
	}

	if (apply)
	{
		applied_effects.emplace_back(*this);
	}

	return true;
}

bool Cold::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_COLD) == 0;
}
