#pragma once

#include <cstring>
#include <string>

#include "Effect.hpp"

class Bleeding: public Effect {
public:
	const int dmgPerRound;

	Bleeding(int dmgPerRound, int duration) 
		: Effect("Bleeding", duration), dmgPerRound{ dmgPerRound } { };

	virtual bool nextRound(Character& affected) override;
	virtual bool addTo(std::vector<Effect>& applied_effects) override;
	virtual bool remove(Character& affected) override;
};