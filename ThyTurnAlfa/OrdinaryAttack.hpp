#pragma once

#ifndef ORDINARY_ATTACK_HPP
#define ORDINARY_ATTACK_HPP

#include "Attack.hpp"

class OrdinaryAttack : public Attack {
	public:
	OrdinaryAttack(int w_move = Const::OrdinaryAttack::ORDINARY_ATTACK_DEFAULT_WEIGHT):
		Attack(Const::OrdinaryAttack::ORDINARY_ATTACK_MOVEMENT_NAME, w_move) { }
};

#endif // !ORDINARY_ATTACK_HPP

