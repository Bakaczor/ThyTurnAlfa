#pragma once

#include "Movement.hpp"

#define BLEEDING_ATTACK_DEFAULT_WEIGHT 60
#define BLEEDING_ATTACK_DEFAULT_EFFECT_DURATION 3
#define BLEEDING_ATTACK_DEFAULT_DAMAGE_PER_ROUND 5

class BleedingAttack : public Movement {
public:
	BleedingAttack() : Movement(TargetEnum::enemy, BLEEDING_ATTACK_DEFAULT_WEIGHT) { }

	virtual bool invoke(Character& who, Character& on_whom) override;
};