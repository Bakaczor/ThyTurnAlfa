#include "Shield.hpp"

bool Shield::addTo(Character& affected, int hp)
{
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++)
	{
		if (dynamic_cast<Shield*>(it->get()))
		{
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
	}

	affected.activeEffects.emplace_back(std::make_unique<Shield>(hp));
	return true;
}
