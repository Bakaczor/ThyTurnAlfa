#pragma once

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <cstring>
#include <string>

class Character;

#include "Character.hpp"

// przenieść do osobnego pliku (skonsultować gdzie)
#pragma region common

#define UNIT_VALUE 100
#define percent(x) x / (float)UNIT_VALUE

enum class TargetEnum {
	enemy,
	ally,
	any
};

#pragma endregion

class Movement {
public:
	const std::string name;
	const TargetEnum target;

	Movement(std::string&& name, const TargetEnum target)
		: name{ name }, target { target } { }

	virtual bool invoke(Character& who, Character& on_whom);
	virtual int getCost() { return 0; };
protected:
	virtual bool isInvokable(Character& who, Character& on_whom);
	// individualAction method should return false if on_whom.currentHp is not greater than 0 and true in other cases
	virtual bool individualAction(Character& who, Character& on_whom) { return true; };
	virtual void addEffects(Character& who, Character& on_whom) { }; // should be overridden by movement which applies effect(s)
};

#endif // !MOVEMENT_HPP


