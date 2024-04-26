#pragma once

#ifndef LIGHTNING_ATTACK_HPP
#define LIGHTNING_ATTACK_HPP

#include "MagicAttack.hpp"

class LightningAttack : public MagicAttack {
	public:
	LightningAttack(int cost = Const::LightningAttack::LIGHTNING_ATTACK_DEFAULT_COST,
					int w_move = Const::LightningAttack::LIGHTNING_ATTACK_DEFAULT_WEIGHT
	): MagicAttack(Const::LightningAttack::LIGHTNING_ATTACK_MOVEMENT_NAME, cost, w_move) { }
	protected:
	virtual bool individualAction(Character& who, Character& on_whom) override;
};

#endif // !LIGHTNING_ATTACK_HPP