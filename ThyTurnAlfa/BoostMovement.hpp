#pragma once

#ifndef BOOST_MOVEMENT_HPP
#define BOOST_MOVEMENT_HPP

#include "DefensiveMovement.hpp"
#include "Boost.hpp"

#define BOOST_MOVEMENT_DEFAULT_COST 20
#define BOOST_MOVEMENT_DEFAULT_EFFECT_DURATION 3
#define BOOST_MOVEMENT_DEFAULT_ATK_BOOST_VALUE 30
#define BOOST_MOVEMENT_DEFAULT_DEF_BOOST_VALUE 30

class BoostMovement : public DefensiveMovement {
public:
	BoostMovement(int cost = BOOST_MOVEMENT_DEFAULT_COST): DefensiveMovement(cost) {}

protected:
	// isInvokable taken from DefensiveMovement
	// individualAction taken from Effect
	virtual void addEffects(Character& who, Character& on_whom) override 
	{
		Boost::addTo(on_whom, BOOST_MOVEMENT_DEFAULT_EFFECT_DURATION,
			BOOST_MOVEMENT_DEFAULT_ATK_BOOST_VALUE, BOOST_MOVEMENT_DEFAULT_DEF_BOOST_VALUE);
	}
};

#endif // !BOOST_MOVEMENT_HPP
