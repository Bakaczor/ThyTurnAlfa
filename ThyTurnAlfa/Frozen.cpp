#include "Frozen.hpp"

bool Frozen::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_FROZEN) == 0;
}
