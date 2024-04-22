#pragma once

#ifndef FIRE_ATTACK_HPP
#define FIRE_ATTACK_HPP

#include "MagicAttack.hpp"

#define FIRE_ATTACK_DEFAULT_WEIGHT 60
#define FIRE_ATTACK_DEFAULT_COST 40
#define FIRE_ATTACK_DEFAULT_DAMAGE_PER_ROUND 10
#define FIRE_ATTACK_DEFAULT_EFFECT_DURATION 4

class FireAttack : public MagicAttack {
public:
	FireAttack()
		: MagicAttack(FIRE_ATTACK_DEFAULT_COST, FIRE_ATTACK_DEFAULT_WEIGHT) { }

	virtual void addEffects(Character& who, Character& on_whom) override;
};

#endif // !FIRE_ATTACK_HPP
