#pragma once

#include "Attack.hpp"

class MagicAttack : public Attack {
public:
	const unsigned cost;

	MagicAttack(int cost, int w_move, int w_pierce = 0) 
		: Attack(w_move, w_pierce), cost{ cost }, m_string_cost{cost} { }

	virtual bool isExecutable(Character& who, Character& on_whom) override;
	virtual std::string getCost() override;
private:
	std::string intToString(int x);
	const std::string m_string_cost;
};