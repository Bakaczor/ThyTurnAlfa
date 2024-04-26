#pragma once

#ifndef WATER_ATTACK_HPP
#define WATER_ATTACK_HPP

#include "MagicAttack.hpp"
#include "Wet.hpp"

class WaterAttack : public MagicAttack {
	public:
	WaterAttack(int cost = Const::WaterAttack::WATER_ATTACK_DEFAULT_COST, 
				int w_move = Const::WaterAttack::WATER_ATTACK_DEFAULT_WEIGHT
	): MagicAttack(Const::WaterAttack::WATER_ATTACK_MOVEMENT_NAME, cost, w_move) { }

	virtual void addEffects(Character& who, Character& on_whom) override
	{
		Wet::addTo(on_whom, 
				   Const::WaterAttack::WATER_ATTACK_DEFAULT_EFFECT_DURATION,
				   Const::WaterAttack::WATER_ATTACK_DEFAULT_FROZEN_EFFECT_DURATION);
	}
};

#endif // !WATER_ATTACK_HPP