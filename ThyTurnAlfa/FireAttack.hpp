#pragma once

#ifndef FIRE_ATTACK_HPP
#define FIRE_ATTACK_HPP

#include "MagicAttack.hpp"
#include "Burning.hpp"

class FireAttack : public MagicAttack {
	public:
	FireAttack(int cost = Const::FireAttack::FIRE_ATTACK_DEFAULT_COST,
			   int w_move = Const::FireAttack::FIRE_ATTACK_DEFAULT_WEIGHT
	): MagicAttack(Const::FireAttack::FIRE_ATTACK_MOVEMENT_NAME, cost, w_move) { }

	virtual void addEffects(Character& who, Character& on_whom) final;
};

#endif // !FIRE_ATTACK_HPP
