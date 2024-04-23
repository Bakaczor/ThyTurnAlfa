#pragma once

#ifndef ICE_ATTACK_HPP
#define ICE_ATTACK_HPP

#include "MagicAttack.hpp"

#define ICE_ATTACK_DEFAULT_WEIGHT 85
#define ICE_ATTACK_DEFAULT_PIERCING_WEIGHT 30
#define ICE_ATTACK_DEFAULT_COST 30

class IceAttack : public MagicAttack {
public:
	IceAttack(int cost = ICE_ATTACK_DEFAULT_COST, int w_move = ICE_ATTACK_DEFAULT_WEIGHT) 
		: MagicAttack(cost, w_move) { }
};

#endif // !ICE_ATTACK_HPP