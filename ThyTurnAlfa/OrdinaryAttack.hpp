#pragma once

#include "Attack.hpp"

#define ORDINARY_ATTACK_DEFAULT_WEIGHT UNIT_VALUE

class OrdinaryAttack: public Attack {
public:
	OrdinaryAttack()
	: Attack(ORDINARY_ATTACK_DEFAULT_WEIGHT) { }

	virtual bool invoke(Character& who, Character& on_whom) override;
};