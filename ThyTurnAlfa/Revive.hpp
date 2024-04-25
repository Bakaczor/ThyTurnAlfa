#pragma once 

#ifndef REVIVE_HPP
#define REVIVE_HPP

#include "DefensiveMovement.hpp"

#define REVIVE_MOVENT_NAME "Revive"
#define REVIVE_DEFAULT_COST 70

class Revive : public DefensiveMovement {
public:
	Revive(int cost = REVIVE_DEFAULT_COST)
		: DefensiveMovement(REVIVE_MOVENT_NAME, cost) { }
	
protected:
	virtual bool isInvokable(Character& who, Character& on_whom) override
	{
		return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp == 0;
	}

	virtual bool individualAction(Character& who, Character& on_whom) override
	{
		on_whom.currentHp = on_whom.hp;
		return true;
	}
};

#endif // !REVIVE_HPP
