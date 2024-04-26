#pragma once 

#ifndef REVIVE_HPP
#define REVIVE_HPP

#include "DefensiveMovement.hpp"

class Revive : public DefensiveMovement {
	public:
	Revive(int cost = Const::Revive::REVIVE_DEFAULT_COST):
		DefensiveMovement(Const::Revive::REVIVE_MOVENT_NAME, cost) { }
	
	private:
	virtual bool isInvokable(Character& who, Character& on_whom) final;
	virtual bool individualAction(Character& who, Character& on_whom) final;
};

#endif // !REVIVE_HPP
