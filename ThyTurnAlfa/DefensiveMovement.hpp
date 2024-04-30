#pragma once

#ifndef DEFENSIVE_MOVEMENT_HPP
#define DEFENSIVE_MOVEMENT_HPP

#include "Movement.hpp"

class Character;

class DefensiveMovement : public Movement {
	public:
	const int cost;
	DefensiveMovement(std::string&& name, int cost);

	virtual int getCost() override;

	protected:
	virtual bool isInvokable(Character& who, Character& on_whom) override;
};

#endif // !DEFENSIVE_MOVEMENT_HPP


