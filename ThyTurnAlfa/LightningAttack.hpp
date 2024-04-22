#pragma once

#ifndef LIGHTNING_ATTACK_HPP
#define LIGHTNING_ATTACK_HPP

#include "MagicAttack.hpp"

#define LIGHTNING_ATTACK_DEFAULT_WEIGHT 100
#define LIGHTNING_ATTACK_DEFAULT_COST 0.5f * LIGHTNING_ATTACK_DEFAULT_WEIGHT

class LightningAttack : public MagicAttack {
public:
	LightningAttack()
		: MagicAttack(LIGHTNING_ATTACK_DEFAULT_COST, LIGHTNING_ATTACK_DEFAULT_WEIGHT) { }
protected:
	virtual void applyDamage(Character& who, Character& on_whom) override;
};

#endif // !#define LIGHTNING_ATTACK_HPP