#pragma once

#include "Attack.hpp"

#define BLEEDING_ATTACK_DEFAULT_WEIGHT 60
#define BLEEDING_ATTACK_DEFAULT_EFFECT_DURATION 3
#define BLEEDING_ATTACK_DEFAULT_DAMAGE_PER_ROUND 5

class BleedingAttack : public Attack {
public:
	BleedingAttack() : Attack(BLEEDING_ATTACK_DEFAULT_WEIGHT) { }

	virtual void addEffects(Character& who, Character& on_whom) override;
};