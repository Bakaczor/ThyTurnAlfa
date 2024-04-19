#pragma once

#include "TemporaryDamagePerRound.hpp"

#define EFFECT_NAME_BLEEDING "Bleeding"

class Bleeding: public TemporaryDamagePerRound {
public:
	Bleeding(int duration, int dmg_per_round)
		: TemporaryDamagePerRound(EFFECT_NAME_BLEEDING, dmg_per_round, duration) { };

	static bool isTypeOf(Effect& e);
};