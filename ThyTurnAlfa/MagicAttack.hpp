#pragma once

#include "Attack.hpp"

class MagicAttack : public Attack {
public:
	const unsigned cost;

	MagicAttack(int cost, int w_move, int w_pierce = 0) 
		: Attack(w_move, w_pierce), cost{ (unsigned)cost } { }

	virtual bool isExecutable(Character& who, Character& on_whom) override;
	virtual int getCost() override;
};