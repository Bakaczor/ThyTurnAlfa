#pragma once

#include "TemporaryDamageModifier.hpp"

#define EFFECT_NAME_BOOST "Boost"

class Boost : public TemporaryDamageModifier {
public:
	Boost(int duration, unsigned atkBoost, unsigned defBoost)
		: TemporaryDamageModifier(EFFECT_NAME_BOOST, atkBoost, defBoost, duration) { };
	
	virtual bool addTo(std::vector<std::unique_ptr<Effect>>& applied_effects) override;
};