#pragma once

#ifndef BOOST_MOVEMENT_HPP
#define BOOST_MOVEMENT_HPP

#include "DefensiveMovement.hpp"

class Character;

class BoostMovement : public DefensiveMovement {
	public:
	BoostMovement();
	virtual bool isInvokable(const Character& who, const Character& on_whom) const final;

	private:
	virtual void addEffects(Character& on_whom) final;
};

#endif // !BOOST_MOVEMENT_HPP
