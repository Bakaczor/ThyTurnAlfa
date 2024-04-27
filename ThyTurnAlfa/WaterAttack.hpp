#pragma once

#ifndef WATER_ATTACK_HPP
#define WATER_ATTACK_HPP

#include "MagicAttack.hpp"

class Character;

class WaterAttack : public MagicAttack {
	public:
	WaterAttack();

	virtual void addEffects(Character& on_whom) final;
};

#endif // !WATER_ATTACK_HPP