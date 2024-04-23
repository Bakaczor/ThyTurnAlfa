#pragma once

#ifndef ORDINARY_ATTACK_HPP
#define ORDINARY_ATTACK_HPP

#include "Attack.hpp"

#define ORDINARY_ATTACK_DEFAULT_WEIGHT 100

class OrdinaryAttack : public Attack {
public:
	OrdinaryAttack(int w_move = ORDINARY_ATTACK_DEFAULT_WEIGHT)
		: Attack(w_move) { }
};

#endif // !ORDINARY_ATTACK_HPP

