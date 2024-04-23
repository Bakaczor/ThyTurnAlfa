#pragma once

#ifndef FROZEN_HPP
#define FROZEN_HPP

#include "TemporaryDamageModifier.hpp"

#define EFFECT_NAME_FROZEN "Frozen"
#define FROZEN_DEFAULT_ATK_DROP 10
#define FROZEN_DEFAULT_DEF_DROP 10

class Frozen : public TemporaryDamageModifier {
public:
	Frozen(int duration, unsigned atkDrop = FROZEN_DEFAULT_ATK_DROP, unsigned defDrop = FROZEN_DEFAULT_DEF_DROP)
		: TemporaryDamageModifier(EFFECT_NAME_FROZEN, -(int)atkDrop, -(int)defDrop, duration) { };

	// nextRound and cancelFrom methods are inherited from TemporaryDamageModifier
	static bool addTo(Character& affected, int duration,
		unsigned atkDrop = FROZEN_DEFAULT_ATK_DROP, unsigned defDrop = FROZEN_DEFAULT_DEF_DROP);
};

#endif // !FROZEN_HPP