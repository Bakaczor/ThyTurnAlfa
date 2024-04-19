#pragma once

#include "Effect.hpp"
#include "Character.hpp"

class TemporaryDamagePerRound : public Effect {
public:
	const int dmgPerRound;

	TemporaryDamagePerRound(std::string name, int duration, int dmgPerRound)
		: Effect(name, duration), dmgPerRound{ dmgPerRound } { };
	
	virtual bool nextRound(Character& affected) override;
	virtual bool remove(Character& affected) override;
};