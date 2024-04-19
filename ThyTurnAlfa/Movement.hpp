#pragma once

class Character;

enum class TargetEnum {
	enemy,
	ally,
	any
};

class Movement {
public:
	const TargetEnum target;
	const int w_move;

	Movement(const TargetEnum target, int w_move) : target{ target }, w_move{ w_move } { }

	virtual bool invoke(Character& who, Character& on_whom) = 0;
};