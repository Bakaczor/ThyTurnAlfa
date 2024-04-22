#pragma once

#ifndef HEAL_HPP
#define HEAL_HPP

#include "DefensiveMovement.hpp"

#define HEAL_DEFAULTL_HP_BOOST 50
#define HEAL_DEFAULT_COST 20

class Heal : public DefensiveMovement {
public:
	const int hpBoost;

	Heal(int cost = HEAL_DEFAULT_COST, int hp_boost = HEAL_DEFAULTL_HP_BOOST)
		: DefensiveMovement(cost), hpBoost{hp_boost} { }
protected:
	virtual bool isInvokable(Character& who, Character& on_whom) override;
	virtual bool individualAction(Character& who, Character& on_whom) override;
};

#endif // !HEAL_HPP