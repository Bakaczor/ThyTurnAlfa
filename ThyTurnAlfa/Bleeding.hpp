#pragma once

#include "TemporaryDamagePerRound.hpp"

#define EFFECT_NAME_BLEEDING "Bleeding"

class Bleeding: public TemporaryDamagePerRound {
public:
	Bleeding(int dmgPerRound, int duration) 
		: TemporaryDamagePerRound(EFFECT_NAME_BLEEDING, dmgPerRound, duration) { };

	static bool isTypeOf(Effect& e);
};