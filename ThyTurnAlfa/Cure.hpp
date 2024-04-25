#pragma once

#ifndef CURE_HPP
#define CURE_HPP

#include "DefensiveMovement.hpp"
#include "Bleeding.hpp"

#define CURE_MOVEMENT_NAME "Cure"
#define CURE_DEFAULT_COST 10

class Cure : public DefensiveMovement {
public:
	Cure(int cost = CURE_DEFAULT_COST) : DefensiveMovement(CURE_MOVEMENT_NAME, cost) { }
protected:
	virtual bool individualAction(Character& who, Character& on_whom) override;
};
#endif // !CURE_HPP
