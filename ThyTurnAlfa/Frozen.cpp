#include "Frozen.hpp"
#include "Burning.hpp"

bool Frozen::addTo(std::vector<std::unique_ptr<Effect>>& applied_effects)
{
	bool apply = true;
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (dynamic_cast<Frozen*>(it->get()))
		{
			applied_effects.erase(it);
		}
		else if (dynamic_cast<Burning*>(it->get()))
		{
			applied_effects.erase(it);
			apply = false;
		}
	}
	
	if (apply)
	{
		applied_effects.emplace_back(new Frozen(*this));
	}

	return true;
}

bool Frozen::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_FROZEN) == 0;
}
