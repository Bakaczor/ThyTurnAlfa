#include "Boost.hpp"

bool Boost::addTo(std::vector<std::unique_ptr<Effect>>& applied_effects, int duration, unsigned atkBoost, unsigned defBoost)
{
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (dynamic_cast<Boost*>(it->get()))
		{
			return false;
		}
	}
	applied_effects.emplace_back(std::make_unique<Boost>(duration, atkBoost, defBoost));
	return true;
}
