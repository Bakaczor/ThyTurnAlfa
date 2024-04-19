#include "Cold.hpp"
#include "Wet.hpp"
#include "Burning.hpp"
#include "Frozen.hpp"

bool Cold::addTo(std::vector<std::unique_ptr<Effect>>& applied_effects)
{
	bool apply = true;
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{
		if (dynamic_cast<Cold*>((*it).get()))
		{
			applied_effects.erase(it);
		}
		else if (dynamic_cast<Wet*>((*it).get()))
		{
			applied_effects.erase(it);
			applied_effects.emplace_back(new Frozen(this->duration));
			apply = false;
		} 
		else if (dynamic_cast<Burning*>((*it).get()))
		{
			apply = false;
		}
	}

	if (apply)
	{
		applied_effects.emplace_back(new Cold(*this));
	}

	return true;
}

bool Cold::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_COLD) == 0;
}
