#pragma once

#ifndef BOOST_MOVEMENT_HPP
#define BOOST_MOVEMENT_HPP

#include "DefensiveMovement.hpp"
#include "Boost.hpp"

class BoostMovement : public DefensiveMovement {
	public:
	BoostMovement(int cost = Const::BoostMovement::BOOST_MOVEMENT_DEFAULT_COST):
		DefensiveMovement(Const::BoostMovement::BOOST_MOVEMENT_NAME, cost) {}

	private:
	virtual bool isInvokable(Character& who, Character& on_whom) final;
	// individualAction is inherited from Effect
	virtual void addEffects(Character& who, Character& on_whom) final;
};

#endif // !BOOST_MOVEMENT_HPP
