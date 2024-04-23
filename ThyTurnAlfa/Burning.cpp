#include "Burning.hpp"
#include "Wet.hpp"
#include "Cold.hpp"

bool Burning::addTo(std::vector<std::unique_ptr<Effect>>& applied_effects)
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
		applied_effects.emplace_back(this);
	}

	return true;
}

bool Burning::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_BURNING) == 0;
}
