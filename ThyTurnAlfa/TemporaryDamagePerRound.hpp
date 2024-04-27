#pragma once

#ifndef TEMPORARY_DAMAGE_PER_ROUND_HPP
#define TEMPORARY_DAMAGE_PER_ROUND_HPP

#include "Effect.hpp"

class Character;

class TemporaryDamagePerRound : public Effect {
	public:
	const int dmgPerRound;

	TemporaryDamagePerRound(std::string name, int duration, int dmgPerRound);

	virtual bool nextRound(Character& affected) override;
	// cancelFrom method is inherited from Effect
};

#endif // !TEMPORARY_DAMAGE_PER_ROUND_HPP