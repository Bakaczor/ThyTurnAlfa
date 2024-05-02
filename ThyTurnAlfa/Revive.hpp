#pragma once 

#ifndef REVIVE_HPP
#define REVIVE_HPP

#include "DefensiveMovement.hpp"

class Character;

class Revive : public DefensiveMovement {
	public:
	Revive();
	virtual bool isInvokable(const Character& who, const Character& on_whom) const final;

	private:
	virtual bool individualAction(Character& who, Character& on_whom) final;
};

#endif // !REVIVE_HPP
