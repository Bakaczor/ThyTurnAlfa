#pragma once

#ifndef BURNING_HPP
#define BURNING_HPP

#include "TemporaryDamagePerRound.hpp"

class Burning : public TemporaryDamagePerRound {
	public:
	Burning(int duration, 
			int dmgPerRound = Const::Buring::BURNING_DEFAULT_DAMAGE_PER_ROUND
	): TemporaryDamagePerRound(Const::Buring::BURNING_EFFECT_NAME, duration, dmgPerRound) { };

	// nextRound method is inherited from TemporaryDamagePerRound
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected, int duration,
		int damager_per_round = Const::Buring::BURNING_DEFAULT_DAMAGE_PER_ROUND);
};

#endif // !BURNING_HPP