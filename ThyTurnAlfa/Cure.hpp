#pragma once

#ifndef CURE_HPP
#define CURE_HPP

#include "Bleeding.hpp"
#include "DefensiveMovement.hpp"

class Cure : public DefensiveMovement {
	public:
	Cure();

	private:
	// isInvokable inherited from DefensiveMovement
	virtual bool individualAction(Character& who, Character& on_whom) final;
};
#endif // !CURE_HPP
