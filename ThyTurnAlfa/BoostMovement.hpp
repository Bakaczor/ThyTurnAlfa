#pragma once

#ifndef BOOST_MOVEMENT_HPP
#define BOOST_MOVEMENT_HPP

#include "Boost.hpp"
#include "DefensiveMovement.hpp"

class BoostMovement : public DefensiveMovement {
	public:
	BoostMovement();

	private:
	virtual bool isInvokable(Character& who, Character& on_whom) final;
	virtual void addEffects(Character& who, Character& on_whom) final;
};

#endif // !BOOST_MOVEMENT_HPP
