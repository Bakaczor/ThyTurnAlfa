#pragma once

#include "TemporaryDamageModifier.hpp"

#define EFFECT_NAME_BOOST "Boost"

class Boost : public TemporaryDamageModifier {
public:
	Boost(unsigned atkBoost, unsigned defBoost, int duration)
		: TemporaryDamageModifier(EFFECT_NAME_BOOST, atkBoost, defBoost, duration) { };

	static bool isTypeOf(Effect& e);
};