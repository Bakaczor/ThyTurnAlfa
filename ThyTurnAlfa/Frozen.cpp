#include "Frozen.hpp"

bool Frozen::addTo(std::vector<Effect>& applied_effects)
{
	// TODO
	return false;
}

bool Frozen::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_FROZEN) == 0;
}
