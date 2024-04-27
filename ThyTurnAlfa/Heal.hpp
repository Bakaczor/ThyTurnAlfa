#pragma once

#ifndef HEAL_HPP
#define HEAL_HPP

#include "DefensiveMovement.hpp"

class Heal : public DefensiveMovement {
	public:
	const int hpBoost = Const::Heal::HEAL_DEFAULTL_HP_BOOST;

	Heal();

	private:
	virtual bool isInvokable(Character& who, Character& on_whom) final;
	virtual bool individualAction(Character& who, Character& on_whom) final;
};

#endif // !HEAL_HPP