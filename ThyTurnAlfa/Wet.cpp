#include "Wet.hpp"
#include "Burning.hpp"
#include "Cold.hpp"
#include "Frozen.hpp"

bool Wet::addTo(std::vector<Effect>& applied_effects)
{
	bool apply = true;
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (it->isTypeOf(*this) || Burning::isTypeOf(*it))
		{
			applied_effects.erase(it);
		}
		else if (Cold::isTypeOf(*it))
		{
			applied_effects.erase(it);
			apply = false;
			Frozen frozen_effect = Frozen(this->duration); // default modifiers passed
			applied_effects.emplace_back(frozen_effect);
		}
	}

	if (apply)
	{
		applied_effects.emplace_back(*this);
	}

	return true;
}

bool Wet::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_WET) == 0;
}
