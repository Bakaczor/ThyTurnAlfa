#pragma once

#ifndef ICE_ATTACK_HPP
#define ICE_ATTACK_HPP

#include "MagicAttack.hpp"

class IceAttack : public MagicAttack {
public:
	IceAttack(int cost = Const::IceAttack::ICE_ATTACK_DEFAULT_COST,
			  int w_move = Const::IceAttack::ICE_ATTACK_DEFAULT_WEIGHT
	): MagicAttack(Const::IceAttack::ICE_ATTACK_MOVEMENT_NAME, cost, w_move) { }
};

#endif // !ICE_ATTACK_HPP