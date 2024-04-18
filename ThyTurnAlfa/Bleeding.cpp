#include "Bleeding.hpp"

bool Bleeding::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_BLEEDING) == 0;
}
