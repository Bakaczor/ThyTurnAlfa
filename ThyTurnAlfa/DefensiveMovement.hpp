#pragma once

#ifndef DEFENSIVE_MOVEMENT_HPP
#define DEFENSIVE_MOVEMENT_HPP

#include "Movement.hpp"

class DefensiveMovement : public Movement {
public:
	const unsigned cost;
	DefensiveMovement(int cost)
		: Movement(TargetEnum::ally), cost{ (unsigned)cost } {}

	virtual int getCost() override
	{
		return this->cost;
	}
protected:
	virtual bool isInvokable(Character& who, Character& on_whom) override
	{
		return Movement::isInvokable(who, on_whom) && who.mp >= cost;
	}
};

#endif // !DEFENSIVE_MOVEMENT_HPP


