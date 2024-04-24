#pragma once

#ifndef LIGHTNING_ATTACK_HPP
#define LIGHTNING_ATTACK_HPP

#include "MagicAttack.hpp"


#define LIGHTNING_ATTACK_MOVEMENT_NAME "LightningAttack"
#define LIGHTNING_ATTACK_DEFAULT_WEIGHT 100
#define LIGHTNING_ATTACK_DEFAULT_COST 0.5f * LIGHTNING_ATTACK_DEFAULT_WEIGHT

class LightningAttack : public MagicAttack {
public:
	LightningAttack(int cost = LIGHTNING_ATTACK_DEFAULT_COST, int w_move = LIGHTNING_ATTACK_DEFAULT_WEIGHT)
		: MagicAttack(LIGHTNING_ATTACK_MOVEMENT_NAME, cost, w_move) { }
protected:
	virtual bool individualAction(Character& who, Character& on_whom) override;
};

#endif // !LIGHTNING_ATTACK_HPP