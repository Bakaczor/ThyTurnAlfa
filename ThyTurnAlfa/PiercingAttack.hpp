#pragma once

#include "Attack.hpp"

#define PIERCING_ATTACK_DEFAULT_WEIGHT 50
#define PIERCING_ATTACK_DEFAULT_PIERCING_WEIGHT 50

class PiercingAttack : public Attack {
public:
	PiercingAttack() 
	: Attack(PIERCING_ATTACK_DEFAULT_WEIGHT, 
		PIERCING_ATTACK_DEFAULT_PIERCING_WEIGHT) { }

	virtual bool invoke(Character& who, Character& on_whom) override;
};