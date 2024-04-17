#pragma once

#include "Character.hpp"

enum class TargetEnum {
	enemy,
	ally,
	any
};

class Movement {
public:
	const TargetEnum target;

	Movement(const TargetEnum target) : target{target} { }
	virtual bool invoke(Character& who, Character& on_whom) = 0;
};