#include "Boost.hpp"

bool Boost::addTo(Character& affected, int duration, unsigned atkBoost, unsigned defBoost)
{
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++)
	{
		if (dynamic_cast<Boost*>(it->get()))
		{
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
	}
	affected.activeEffects.emplace_back(std::make_unique<Boost>(duration, atkBoost, defBoost));
	return true;
}
