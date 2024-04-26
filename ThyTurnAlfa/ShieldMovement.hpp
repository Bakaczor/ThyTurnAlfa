#pragma once

#ifndef SHIELD_MOVEMENT_HPP
#define SHIELD_MOVEMENT_HPP

#include "DefensiveMovement.hpp"
#include "Shield.hpp"

class ShieldMovement : public DefensiveMovement {
	public:
	const int shieldHp;

	ShieldMovement(int cost = Const::ShieldMovement::SHIELD_MOVEMENT_DEFAULT_COST,
				   int shield_hp = Const::ShieldMovement::SHIELD_MOVEMENT_DEFAULT_HP
	): DefensiveMovement(Const::ShieldMovement::SHIELD_MOVEMENT_NAME, cost), shieldHp{shield_hp} { }

	private:
	virtual bool isInvokable(Character& who, Character& on_whom) final;
	virtual void addEffects(Character& who, Character& on_whom) final;
};

#endif // !SHIELD_HPP
