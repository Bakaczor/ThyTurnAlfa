#pragma once

#include <cstring>
#include <string>

#define UNIT_VALUE 100.0f
#define UNIT_DEF_VALUE UNIT_VALUE
#define MIN_DEF_VALUE 0
#define UNIT_ATK_VALUE UNIT_VALUE
#define MIN_ATK_VALUE 0

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
	const float wMove;
	const float wPierce;

	Movement(const TargetEnum target, int w_move, int w_pierce = 0)
		: target{ target }, wMove{ w_move / UNIT_VALUE }, wPierce{ w_pierce / UNIT_VALUE } { }

	virtual bool invoke(Character& who, Character& on_whom) = 0;
	virtual int getCost() { return 0; };
protected:
	int computeDMG(Character& who, Character& on_whom);
	virtual bool isExecutable(Character& who, Character& on_whom) = 0;
	virtual void addEffects(Character& who, Character& on_whom) { } ; // should be overridden by movement which applies effect(s)
};