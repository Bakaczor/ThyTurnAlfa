#include "Cold.hpp"

bool Cold::addTo(std::vector<Effect>& applied_effects)
{
	// TODO
	return false;
}

bool Cold::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_COLD) == 0;
}
