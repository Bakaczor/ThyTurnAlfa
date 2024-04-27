#pragma once 

#ifndef REVIVE_HPP
#define REVIVE_HPP

#include "DefensiveMovement.hpp"

class Character;

class Revive : public DefensiveMovement {
	public:
	Revive();
	
	private:
	virtual bool isInvokable(Character& who, Character& on_whom) final;
	virtual bool individualAction(Character& who, Character& on_whom) final;
};

#endif // !REVIVE_HPP
