#include "Boost.hpp"

bool Boost::addTo(std::vector<Effect>& applied_effects)
{
	// TODO
	return false;
}

bool Boost::isTypeOf(Effect& e)
{
	return e.name.compare(EFFECT_NAME_BOOST) == 0;
}
