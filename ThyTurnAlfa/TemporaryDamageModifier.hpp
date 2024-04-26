#pragma once

#ifndef TEMPORARY_DAMAGE_MODIFIER_HPP
#define TEMPORARY_DAMAGE_MODIFIER_HPP

#include "Effect.hpp"

class TemporaryDamageModifier : public Effect {
	public:
	int atkModifier;
	int defModifier;

	TemporaryDamageModifier(std::string name, int duration, int atkModifier, int defModifier);

	virtual bool nextRound(Character& affected) override;
	virtual bool cancelFrom(Character& affected) override;
};

#endif // !TEMPORARY_DAMAGE_MODIFIER_HPP