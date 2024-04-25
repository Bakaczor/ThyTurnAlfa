#pragma once

#ifndef BLEEDING_HPP
#define BLEEDING_HPP

#include "TemporaryDamagePerRound.hpp"
#include "Character.hpp"

#define BLEEDING_EFFECT_NAME "Bleeding"
#define BLEEDING_DEFAULT_DAMAGE_PER_ROUND 5

class Bleeding : public TemporaryDamagePerRound {
public:
	Bleeding(int duration, int dmg_per_round)
		: TemporaryDamagePerRound(BLEEDING_EFFECT_NAME, duration, dmg_per_round) { };

	// nextRound methods is inherited from ActionlessEffect
	// cancelFrom methods is inherited from Effect
	static bool addTo(Character& affected, int duration,
		int damage_per_round = BLEEDING_DEFAULT_DAMAGE_PER_ROUND);
};

#endif // !BLEEDING_HPP