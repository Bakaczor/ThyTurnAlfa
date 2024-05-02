#pragma once

#ifndef DEFENSIVE_MOVEMENT_HPP
#define DEFENSIVE_MOVEMENT_HPP

#include "Movement.hpp"

class Character;

class DefensiveMovement : public Movement {
	public:
	const int cost;
	const MovementType type = MovementType::Defensive;

	DefensiveMovement(std::string&& name, int cost);

	virtual int getCost() override;
	virtual bool isInvokable(const Character& who, const Character& on_whom) const override;
};

#endif // !DEFENSIVE_MOVEMENT_HPP


