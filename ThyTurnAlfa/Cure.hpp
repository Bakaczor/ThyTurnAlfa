#pragma once

#ifndef CURE_HPP
#define CURE_HPP

#include "DefensiveMovement.hpp"
#include "Bleeding.hpp"

class Cure : public DefensiveMovement {
	public:
	Cure(int cost = Const::Cure::CURE_DEFAULT_COST): DefensiveMovement(Const::Cure::CURE_MOVEMENT_NAME, cost) { }

	private:
	virtual bool individualAction(Character& who, Character& on_whom) final;
};
#endif // !CURE_HPP
