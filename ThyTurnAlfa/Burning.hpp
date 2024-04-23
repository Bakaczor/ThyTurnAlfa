#pragma once

#include "TemporaryDamagePerRound.hpp"

#define EFFECT_NAME_BURNING "Burning"
#define BURNING_DEFAULT_DAMAGE_PER_ROUND 10

class Burning : public TemporaryDamagePerRound {
public:
	Burning(int duration, int dmgPerRound = BURNING_DEFAULT_DAMAGE_PER_ROUND)
		: TemporaryDamagePerRound(EFFECT_NAME_BURNING, duration, dmgPerRound) { };

	static bool addTo(std::vector<std::unique_ptr<Effect>>& applied_effects, int duration, int damager_per_round = BURNING_DEFAULT_DAMAGE_PER_ROUND);
};