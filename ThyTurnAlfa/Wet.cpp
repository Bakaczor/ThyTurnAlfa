#include "Wet.hpp"

bool Wet::addTo(std::vector<Effect>& applied_effects)
{
	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
	{

	}
	return false;
}

bool Wet::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_WET) == 0;
}
