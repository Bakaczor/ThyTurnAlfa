#pragma once

#ifndef PIERCING_ATTACK_HPP
#define PIERCING_ATTACK_HPP

#include "Attack.hpp"

#define PIERCING_ATTACK_DEFAULT_WEIGHT 50
#define PIERCING_ATTACK_DEFAULT_PIERCING_WEIGHT 50

class PiercingAttack : public Attack {
public:
	PiercingAttack()
		: Attack(PIERCING_ATTACK_DEFAULT_WEIGHT,
			PIERCING_ATTACK_DEFAULT_PIERCING_WEIGHT) { }
};

#endif // !PIERCING_ATTACK_HPP

