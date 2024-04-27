#pragma once

#ifndef WATER_ATTACK_HPP
#define WATER_ATTACK_HPP

#include "MagicAttack.hpp"

class WaterAttack : public MagicAttack {
	public:
	WaterAttack();

	private:
	virtual void addEffects(Character& on_whom) final;
};

#endif // !WATER_ATTACK_HPP