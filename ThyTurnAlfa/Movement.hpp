#pragma once

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <cstring>
#include <string>

#include "Character.hpp"

#define UNIT_VALUE 100
#define percent(x) x / (float)UNIT_VALUE

enum class TargetEnum {
	enemy,
	ally,
	any
};

class Movement {
public:
	const std::string name;
	const TargetEnum target;

	Movement(const TargetEnum target)
		: target{ target } { }

	virtual bool invoke(Character& who, Character& on_whom);
	virtual int getCost() { return 0; };
protected:
	virtual bool isInvokable(Character& who, Character& on_whom) = 0;
	virtual bool individualAction(Character& who, Character& on_whom) = 0;
	virtual void addEffects(Character& who, Character& on_whom) { }; // should be overridden by movement which applies effect(s)
};

#endif // !MOVEMENT_HPP


