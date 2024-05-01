#pragma once

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <cstring>
#include <string>

#include "MovementType.hpp"
#include "TargetType.hpp"

class Character;

class Movement {
	public:
	const std::string name;
	const TargetType target;

	Movement(std::string&& name, const TargetType target): name{ name }, target { target } { }
	bool invoke(Character& who, Character& on_whom);

	virtual int getCost();
	virtual bool isInvokable(const Character& who, const Character& on_whom) const;

	protected:
	// should return false if on_whom.currentHp is not greater than 0 and true in other cases
	virtual bool individualAction(Character& who, Character& on_whom);

	// should be overridden by movement which applies effect(s)
	virtual void addEffects(Character& on_whom);
};

#endif // !MOVEMENT_HPP


