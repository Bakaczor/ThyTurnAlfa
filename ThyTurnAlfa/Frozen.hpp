#pragma once

#include "TemporaryDamageModifier.hpp"

#define EFFECT_NAME_FROZEN "Frozen"
#define DEFAULT_ATK_DROP 10
#define DEFAULT_DEF_DROP 10

class Frozen : public TemporaryDamageModifier {
public:
	Frozen(int duration, unsigned atkDrop = DEFAULT_ATK_DROP, unsigned defDrop = DEFAULT_DEF_DROP)
	: TemporaryDamageModifier(EFFECT_NAME_FROZEN, -(int)atkDrop, -(int)defDrop, duration) { };

	virtual bool addTo(std::vector<std::unique_ptr<Effect>>& applied_effects) override;
	static bool isTypeOf(Effect& e);
};