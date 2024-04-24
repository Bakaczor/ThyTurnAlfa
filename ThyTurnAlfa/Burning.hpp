#pragma once

#ifndef BURNING_HPP
#define BURNING_HPP

#include "TemporaryDamagePerRound.hpp"

#define BURNING_EFFECT_NAME "Burning"
#define BURNING_DEFAULT_DAMAGE_PER_ROUND 10

class Burning : public TemporaryDamagePerRound {
public:
	Burning(int duration, int dmgPerRound = BURNING_DEFAULT_DAMAGE_PER_ROUND)
		: TemporaryDamagePerRound(BURNING_EFFECT_NAME, duration, dmgPerRound) { };

	// nextRound method is inherited from TemporaryDamagePerRound
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected, int duration,
		int damager_per_round = BURNING_DEFAULT_DAMAGE_PER_ROUND);
};

#endif // !BURNING_HPP