#pragma once

#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "Effect.hpp"

#define SHIELD_EFFECT_NAME "Shield"
#define SHIELD_DEFAULT_DURATION INFINITE_DURATION
#define SHIELD_DEFAULT_HP 50 

class Shield : public Effect {
public:
	int hp;

	Shield(int hp) 
		: Effect(SHIELD_EFFECT_NAME, SHIELD_DEFAULT_DURATION), hp{ hp }{ }

	virtual bool nextRound(Character& affected) override { return hp > 0; }
	// cancelFrom is inherited from Effect
	static bool addTo(Character& affected, int hp = SHIELD_DEFAULT_HP);
};

#endif // !SHIELD_HPP