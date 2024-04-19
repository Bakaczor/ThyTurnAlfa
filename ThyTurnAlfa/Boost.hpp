#pragma once

#include "TemporaryDamageModifier.hpp"

#define EFFECT_NAME_BOOST "Boost"

class Boost : public TemporaryDamageModifier {
public:
	Boost(int duration, unsigned atkBoost, unsigned defBoost)
		: TemporaryDamageModifier(EFFECT_NAME_BOOST, atkBoost, defBoost, duration) { };
	
	static bool isTypeOf(Effect& e);
};