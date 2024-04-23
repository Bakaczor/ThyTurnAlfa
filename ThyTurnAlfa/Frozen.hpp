#pragma once

#include "TemporaryDamageModifier.hpp"

#define EFFECT_NAME_FROZEN "Frozen"
#define FROZEN_DEFAULT_ATK_DROP 10
#define FROZEN_DEFAULT_DEF_DROP 10

class Frozen : public TemporaryDamageModifier {
public:
	Frozen(int duration, unsigned atkDrop = FROZEN_DEFAULT_ATK_DROP, unsigned defDrop = FROZEN_DEFAULT_DEF_DROP)
	: TemporaryDamageModifier(EFFECT_NAME_FROZEN, -(int)atkDrop, -(int)defDrop, duration) { };

	static bool addTo(std::vector<std::unique_ptr<Effect>>& applied_effects, int duration, 
		unsigned atkDrop = FROZEN_DEFAULT_ATK_DROP, unsigned defDrop = FROZEN_DEFAULT_DEF_DROP);
};