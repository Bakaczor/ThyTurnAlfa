#pragma once

#ifndef FIRE_ATTACK_HPP
#define FIRE_ATTACK_HPP

#include "MagicAttack.hpp"
#include "Burning.hpp"

#define FIRE_ATTACK_MOVEMENT_NAME "FireAttack"
#define FIRE_ATTACK_DEFAULT_WEIGHT 60
#define FIRE_ATTACK_DEFAULT_COST 40
#define FIRE_ATTACK_DEFAULT_DAMAGE_PER_ROUND 10
#define FIRE_ATTACK_DEFAULT_EFFECT_DURATION 4

class FireAttack : public MagicAttack {
public:
	FireAttack(int cost = FIRE_ATTACK_DEFAULT_COST, int w_move = FIRE_ATTACK_DEFAULT_WEIGHT)
		: MagicAttack(FIRE_ATTACK_MOVEMENT_NAME, cost, w_move) { }

	virtual void addEffects(Character& who, Character& on_whom) override 
	{
		Burning::addTo(on_whom, FIRE_ATTACK_DEFAULT_EFFECT_DURATION, 
			FIRE_ATTACK_DEFAULT_DAMAGE_PER_ROUND);
	}
};

#endif // !FIRE_ATTACK_HPP
