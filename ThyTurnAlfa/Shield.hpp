#pragma once

#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "Effect.hpp"

class Shield : public Effect {
public:
	int hp;

	Shield(int hp): Effect(Const::Shield::SHIELD_EFFECT_NAME, Const::Shield::SHIELD_DEFAULT_DURATION), hp{ hp }{ }

	virtual bool nextRound(Character& affected) override { return hp > 0; }
	// cancelFrom is inherited from Effect
	static bool addTo(Character& affected, int hp = Const::Shield::SHIELD_DEFAULT_HP);
};

#endif // !SHIELD_HPP