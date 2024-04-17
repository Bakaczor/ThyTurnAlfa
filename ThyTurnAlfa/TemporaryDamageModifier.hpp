#pragma once

#include "Effect.hpp"

class TemporaryDamageModifier : public Effect {
public:
	int atkModifier;
	int defModifier;
	
	TemporaryDamageModifier(std::string name, int atkModifier, int defModifier, int duration) 
		: Effect(name, duration), atkModifier{ atkModifier }, defModifier{ defModifier } { };

	virtual bool nextRound(Character& affected) override;
	virtual bool remove(Character& affected) override;
};