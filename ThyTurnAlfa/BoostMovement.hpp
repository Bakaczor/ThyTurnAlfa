#pragma once
#ifndef BOOST_MOVEMENT_HPP
#define BOOST_MOVEMENT_HPP

#include "DefensiveMovement.hpp"
#include "Boost.hpp"

#define BOOST_MOVEMENT_DEFAULT_COST 20

class BoostMovement : public DefensiveMovement {
public:
	BoostMovement(int cost = BOOST_MOVEMENT_DEFAULT_COST): DefensiveMovement(cost) {}

protected:
	// isInvokable taken from DefensiveMovement
	// individualAction taken from Effect
	virtual void addEffects(Character& who, Character& on_whom) override;
};

#endif // !BOOST_MOVEMENT_HPP
