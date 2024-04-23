#include "Boost.hpp"

bool Boost::addTo(std::vector<std::unique_ptr<Effect>>& applied_effects)
{
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (dynamic_cast<Boost*>(it->get()))
		{
			return false;
		}
	}
	applied_effects.emplace_back(new Boost(*this));
	return true;
}
