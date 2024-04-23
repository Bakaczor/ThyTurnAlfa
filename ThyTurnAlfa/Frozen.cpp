#include "Frozen.hpp"
#include "Burning.hpp"

bool Frozen::addTo(Character& affected, int duration, unsigned atk_drop, unsigned def_drop)
{
	bool apply = true;
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++)
	{
		if (dynamic_cast<Frozen*>(it->get()))
		{
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
		else if (dynamic_cast<Burning*>(it->get()))
		{
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
			apply = false;
		}
	}
	
	if (apply)
	{
		affected.activeEffects.emplace_back(std::make_unique<Frozen>(duration, atk_drop, def_drop));
	}

	return true;
}
