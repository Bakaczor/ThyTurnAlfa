#pragma once

#ifndef SHIELD_MOVEMENT_HPP
#define SHIELD_MOVEMENT_HPP

#include "DefensiveMovement.hpp"
#include "Shield.hpp"

#define SHIELD_MOVEMENT_NAME "ShieldMovement"
#define SHIELD_MOVEMENT_DEFAULT_HP 40
#define SHIELD_MOVEMENT_DEFAULT_COST 50

class ShieldMovement : public DefensiveMovement {
public:
	const int shieldHp;

	ShieldMovement(int cost = SHIELD_MOVEMENT_DEFAULT_COST, int shield_hp = SHIELD_MOVEMENT_DEFAULT_HP)
		: DefensiveMovement(SHIELD_MOVEMENT_NAME, cost), shieldHp{shield_hp} { }
protected:
	virtual bool isInvokable(Character& who, Character& on_whom) override 
	{ 
		return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp > 0; 
	}
	virtual void addEffects(Character& who, Character& on_whom) override
	{
		Shield::addTo(on_whom, SHIELD_MOVEMENT_DEFAULT_HP);
	}
};

#endif // !SHIELD_HPP
