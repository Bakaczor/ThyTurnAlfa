#pragma once

#ifndef FROZEN_HPP
#define FROZEN_HPP

#include "TemporaryDamageModifier.hpp"

class Frozen : public TemporaryDamageModifier {
	public:
	Frozen(int duration, 
		   unsigned atkDrop = Const::Frozen::FROZEN_DEFAULT_ATK_DROP, 
		   unsigned defDrop = Const::Frozen::FROZEN_DEFAULT_DEF_DROP
	): TemporaryDamageModifier(Const::Frozen::FROZEN_EFFECT_NAME, -(int)atkDrop, -(int)defDrop, duration) { };

	// nextRound and cancelFrom methods are inherited from TemporaryDamageModifier
	static bool addTo(Character& affected, int duration,
					  unsigned atkDrop = Const::Frozen::FROZEN_DEFAULT_ATK_DROP,
					  unsigned defDrop = Const::Frozen::FROZEN_DEFAULT_DEF_DROP);
};

#endif // !FROZEN_HPP