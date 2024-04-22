#pragma once

#ifndef DEFENSIVE_MOVEMENT_HPP
#define DEFENSIVE_MOVEMENT_HPP

#endif // !DEFENSIVE_MOVEMENT_HPP


#include "Movement.hpp"

class DefensiveMovement : public Movement {
public:
	const unsigned cost;
	DefensiveMovement(int cost) 
		: Movement(TargetEnum::ally), cost{ (unsigned)cost } {}
	
	virtual bool invoke(Character& who, Character& on_whom) override;
protected:
	virtual bool isInvokable(Character& who, Character& on_whom) override;
	virtual bool individualAction(Character& who, Character& on_whom) = 0;
};