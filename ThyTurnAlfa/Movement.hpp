#pragma once

#include <cstring>
#include <string>

#define percent(x) x / 100.0f

class Character;

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

	virtual bool invoke(Character& who, Character& on_whom) = 0;
	virtual int getCost() { return 0; };
protected:
	virtual bool isExecutable(Character& who, Character& on_whom) = 0;
	virtual void addEffects(Character& who, Character& on_whom) { } ; // should be overridden by movement which applies effect(s)
};