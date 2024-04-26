#pragma once

#ifndef PIERCING_ATTACK_HPP
#define PIERCING_ATTACK_HPP

#include "Attack.hpp"

class PiercingAttack : public Attack {
	public:
	PiercingAttack(int w_move = Const::PiercingAttack::PIERCING_ATTACK_DEFAULT_WEIGHT,
				   int w_pierce = Const::PiercingAttack::PIERCING_ATTACK_DEFAULT_PIERCING_WEIGHT
	): Attack(Const::PiercingAttack::PIERCING_ATTACK_MOVEMENT_NAME, w_move, w_pierce) { }
};

#endif // !PIERCING_ATTACK_HPP

