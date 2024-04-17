#pragma once

#include "TemporaryDamagePerRound.hpp"

class Burning : public TemporaryDamagePerRound {
public:
	Burning(int dmgPerRound, int duration) : TemporaryDamagePerRound("Burning", dmgPerRound, duration) { };

	virtual bool addTo(std::vector<Effect>& applied_effects) override;
};