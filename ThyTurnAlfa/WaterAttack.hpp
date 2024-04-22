#pragma once

#ifndef WATER_ATTACK_HPP
#define WATER_ATTACK_HPP

#include "MagicAttack.hpp"

#define WATER_ATTACK_DEFAULT_WEIGHT 80
#define WATER_ATTACK_DEFAULT_EFFECT_DURATION 5
#define WATER_ATTACK_DEFAULT_COST 20

class WaterAttack : public MagicAttack {
public:
	WaterAttack() : MagicAttack(WATER_ATTACK_DEFAULT_COST, WATER_ATTACK_DEFAULT_WEIGHT) { }

	virtual void addEffects(Character& who, Character& on_whom) override;
};

#endif // !WATER_ATTACK_HPP