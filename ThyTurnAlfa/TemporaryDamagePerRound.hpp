#pragma once

#ifndef TEMPORARY_DAMAGE_PER_ROUND_HPP
#define TEMPORARY_DAMAGE_PER_ROUND_HPP

#include "Effect.hpp"
#include "Character.hpp"

class TemporaryDamagePerRound : public Effect {
public:
	const int dmgPerRound;

	TemporaryDamagePerRound(std::string name, int duration, int dmgPerRound)
		: Effect(name, duration), dmgPerRound{ dmgPerRound } { };

	virtual bool nextRound(Character& affected) override;
	// cancelFrom method is ingerited from Effect
};

#endif // !TEMPORARY_DAMAGE_PER_ROUND_HPP