#include "Bleeding.hpp"

bool Bleeding::addTo(std::vector<Effect>& applied_effects)
{
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (it->isTypeOf(*this))
		{
			applied_effects.erase(it);
		}
	}
	applied_effects.emplace_back(*this);
	return true;
}

bool Bleeding::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_BLEEDING) == 0;
}
