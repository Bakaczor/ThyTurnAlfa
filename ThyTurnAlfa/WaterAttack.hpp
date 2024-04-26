#pragma once

#ifndef WATER_ATTACK_HPP
#define WATER_ATTACK_HPP

#include "MagicAttack.hpp"
#include "Wet.hpp"

class WaterAttack : public MagicAttack {
	public:
	WaterAttack();

	virtual void addEffects(Character& who, Character& on_whom) final;
};

#endif // !WATER_ATTACK_HPP