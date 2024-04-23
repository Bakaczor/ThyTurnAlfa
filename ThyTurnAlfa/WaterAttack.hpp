#pragma once

#ifndef WATER_ATTACK_HPP
#define WATER_ATTACK_HPP

#include "MagicAttack.hpp"
#include "Wet.hpp"

#define WATER_ATTACK_DEFAULT_WEIGHT 80
#define WATER_ATTACK_DEFAULT_EFFECT_DURATION 5
#define WATER_ATTACK_DEFAULT_FROZEN_EFFECT_DURATION 5
#define WATER_ATTACK_DEFAULT_COST 20

class WaterAttack : public MagicAttack {
public:
	WaterAttack(int cost = WATER_ATTACK_DEFAULT_COST, int w_move = WATER_ATTACK_DEFAULT_WEIGHT) 
		: MagicAttack(cost, w_move) { }

	virtual void addEffects(Character& who, Character& on_whom) override
	{
		Wet::addTo(on_whom, WATER_ATTACK_DEFAULT_EFFECT_DURATION, 
			WATER_ATTACK_DEFAULT_FROZEN_EFFECT_DURATION);
	}
};

#endif // !WATER_ATTACK_HPP