#include "Boost.hpp"

bool Boost::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_BOOST) == 0;
}
