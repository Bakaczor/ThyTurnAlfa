#pragma once

#ifndef BOOST_MOVEMENT_HPP
#define BOOST_MOVEMENT_HPP

#include "DefensiveMovement.hpp"

class Character;

class BoostMovement : public DefensiveMovement {
	public:
	BoostMovement();

	private:
	virtual bool isInvokable(Character& who, Character& on_whom) final;
	virtual void addEffects(Character& on_whom) final;
};

#endif // !BOOST_MOVEMENT_HPP
