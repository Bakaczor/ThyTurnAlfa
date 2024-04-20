#pragma once

#include "Movement.hpp"

#define PIERCING_ATTACK_DEFAULT_WEIGHT 50
#define PIERCING_ATTACK_DEFAULT_PIERCING_VALUE 50

class PiercingAttack : public Movement {
public:
	PiercingAttack() 
	: Movement(TargetEnum::enemy, PIERCING_ATTACK_DEFAULT_WEIGHT, 
		PIERCING_ATTACK_DEFAULT_PIERCING_VALUE) { }
	virtual bool invoke(Character& who, Character& on_whom) override;
};