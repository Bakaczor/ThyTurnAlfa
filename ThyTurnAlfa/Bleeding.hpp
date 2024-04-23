#pragma once

#include "TemporaryDamagePerRound.hpp"

#define EFFECT_NAME_BLEEDING "Bleeding"
#define BLEEDING_DEFAULT_DAMAGE_PER_ROUND 5

class Bleeding: public TemporaryDamagePerRound {
public:
	Bleeding(int duration, int dmg_per_round)
		: TemporaryDamagePerRound(EFFECT_NAME_BLEEDING, duration, dmg_per_round) { };

	static bool addTo(std::vector<std::unique_ptr<Effect>>& applied_effects, int duration, 
		int damage_per_round = BLEEDING_DEFAULT_DAMAGE_PER_ROUND);
};