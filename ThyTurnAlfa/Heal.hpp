#pragma once

#ifndef HEAL_HPP
#define HEAL_HPP

#include "DefensiveMovement.hpp"

class Heal : public DefensiveMovement {
public:
	const int hpBoost;

	Heal(int cost = Const::Heal::HEAL_DEFAULT_COST,
		 int hp_boost = Const::Heal::HEAL_DEFAULTL_HP_BOOST
	): DefensiveMovement(Const::Heal::HEAL_MOVEMENT_NAME, cost), hpBoost{hp_boost} { }

	private:
	virtual bool isInvokable(Character& who, Character& on_whom) final;
	virtual bool individualAction(Character& who, Character& on_whom) final;
};

#endif // !HEAL_HPP