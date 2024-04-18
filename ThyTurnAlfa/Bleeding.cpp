#include "Bleeding.hpp"

bool Bleeding::addTo(std::vector<Effect>& applied_effects)
{
	
}

bool Bleeding::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_BLEEDING) == 0;
}
