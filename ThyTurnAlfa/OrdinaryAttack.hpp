#pragma once

#include "Movement.hpp"

#define ORDINARY_ATTACK_DEFAULT_WEIGHT UNIT_VALUE

class OrdinaryAttack: public Movement {
public:
	OrdinaryAttack()
	: Movement(TargetEnum::enemy, ORDINARY_ATTACK_DEFAULT_WEIGHT) { }

	virtual bool invoke(Character& who, Character& on_whom) override;
};