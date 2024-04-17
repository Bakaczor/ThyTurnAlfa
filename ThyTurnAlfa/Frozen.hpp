#pragma once

#include "TemporaryDamageModifier.hpp"

#define EFFECT_NAME_FROZEN "Frozen"

class Frozen : public TemporaryDamageModifier {
public:
	Frozen(unsigned atkDrop, unsigned defDrop, int duration) 
	: TemporaryDamageModifier(EFFECT_NAME_FROZEN, -(int)atkDrop, -(int)defDrop, duration) { };

	virtual bool addTo(std::vector<Effect>& applied_effects) override;
};