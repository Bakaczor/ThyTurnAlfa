#pragma once

#ifndef PIERCING_ATTACK_HPP
#define PIERCING_ATTACK_HPP

#include "Attack.hpp"

#define PIERCING_ATTACK_DEFAULT_WEIGHT 50
#define PIERCING_ATTACK_DEFAULT_PIERCING_WEIGHT 50

class PiercingAttack : public Attack {
public:
	PiercingAttack(int w_move = PIERCING_ATTACK_DEFAULT_WEIGHT, int w_pierce = PIERCING_ATTACK_DEFAULT_PIERCING_WEIGHT)
		: Attack(w_move, w_pierce) { }
};

#endif // !PIERCING_ATTACK_HPP

