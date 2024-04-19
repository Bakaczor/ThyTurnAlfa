#pragma once

#include "TemporaryDamagePerRound.hpp"

#define EFFECT_NAME_BLEEDING "Bleeding"

class Bleeding: public TemporaryDamagePerRound {
public:
	Bleeding(int duration, int dmgPerRound)
		: TemporaryDamagePerRound(EFFECT_NAME_BLEEDING, dmgPerRound, duration) { };

	static bool isTypeOf(Effect& e);
};