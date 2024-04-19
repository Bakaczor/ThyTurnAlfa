#pragma once

#include "TemporaryDamagePerRound.hpp"

#define EFFECT_NAME_BURNING "Burning"

class Burning : public TemporaryDamagePerRound {
public:
	Burning(int duration, int dmgPerRound) : TemporaryDamagePerRound(EFFECT_NAME_BURNING, duration, dmgPerRound) { };

	virtual bool addTo(std::vector<std::unique_ptr<Effect>>& applied_effects) override;
	static bool isTypeOf(Effect& e);
};