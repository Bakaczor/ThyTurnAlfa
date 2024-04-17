#pragma once

#include "Effect.hpp"


class Boost : public Effect {
public:
	const int atkBoost;
	const int defBoost;

	Boost(int atkBoost, int defBoost, int duration)
		: Effect("Boost", duration), atkBoost{atkBoost}, defBoost{defBoost} { }

	virtual bool nextRound(Character& affected) override;
	virtual bool addTo(std::vector<Effect>& applied_effects) override;
	virtual bool remove(Character& affected) override;
};