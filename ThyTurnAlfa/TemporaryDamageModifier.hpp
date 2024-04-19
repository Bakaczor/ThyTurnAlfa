#pragma once

#include "Effect.hpp"
#include "Character.hpp"

class TemporaryDamageModifier : public Effect {
public:
	int atkModifier;
	int defModifier;
	
	TemporaryDamageModifier(std::string name, int duration, int atkModifier, int defModifier)
		: Effect(name, duration), atkModifier{ atkModifier }, defModifier{ defModifier } { };

	virtual bool nextRound(Character& affected) override;
	virtual bool remove(Character& affected) override;
};