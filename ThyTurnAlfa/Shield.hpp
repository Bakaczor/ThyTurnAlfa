#pragma once

#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "Effect.hpp"

#define EFFECT_NAME_SHIELD "Shield"
#define SHIELD_DEFAULT_DURATION INFINITE_DURATION
#define SHIELD_DEFAULT_HP 50 

class Shield : public Effect {
public:
	int hp;

	Shield(int hp) 
		: Effect(EFFECT_NAME_SHIELD, SHIELD_DEFAULT_DURATION), hp{ hp }{ }

	virtual bool nextRound(Character& affected) override { return hp > 0; }
	// cancelFrom is inherited from Effect
	static bool addTo(Character& affected, int hp = SHIELD_DEFAULT_HP);
};

#endif // !SHEILD_HPP