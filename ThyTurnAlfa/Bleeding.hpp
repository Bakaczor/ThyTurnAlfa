#pragma once

#ifndef BLEEDING_HPP
#define BLEEDING_HPP

#include "Character.hpp"
#include "TemporaryDamagePerRound.hpp"

class Bleeding : public TemporaryDamagePerRound {
	public:
	Bleeding(int duration, int dmg_per_round);

	// nextRound methods is inherited from ActionlessEffect
	// cancelFrom methods is inherited from Effect
	static bool addTo(Character& affected, int duration,
					  int damage_per_round = Const::Bleeding::BLEEDING_DEFAULT_DAMAGE_PER_ROUND);
};

#endif // !BLEEDING_HPP