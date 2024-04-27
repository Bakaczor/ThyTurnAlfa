#pragma once

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <cstring>
#include <string>

class Character;

#include "Character.hpp"
#include "TargetType.hpp"
#include "Utils.hpp"

class Movement {
	public:
	const std::string name;
	const TargetType target;

	Movement(std::string&& name, const TargetType target): name{ name }, target { target } { }
	virtual bool invoke(Character& who, Character& on_whom);
	virtual int getCost() { return 0; };

	protected:
	virtual bool isInvokable(Character& who, Character& on_whom);

	// should return false if on_whom.currentHp is not greater than 0 and true in other cases
	virtual bool individualAction(Character& who, Character& on_whom) { return true; };

	// should be overridden by movement which applies effect(s)
	virtual void addEffects(Character& on_whom) { };
};

#endif // !MOVEMENT_HPP


