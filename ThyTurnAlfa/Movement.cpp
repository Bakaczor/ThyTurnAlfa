#include "Character.hpp"
#include "Movement.hpp"
#include "TargetType.hpp"

int Movement::getCost() { return 0; };

bool Movement::individualAction(Character& who, Character& on_whom) { return true; };

void Movement::addEffects(Character& on_whom) {};

bool Movement::invoke(Character& who, Character& on_whom) {
	if (!isInvokable(who, on_whom)) return false;

	if (!individualAction(who, on_whom)) return true;

	addEffects(on_whom);

	return true;
}

bool Movement::isInvokable(Character& who, Character& on_whom) {
	bool are_allies = who.getPlayerId() == on_whom.getPlayerId();
	switch (target) {
	case TargetType::Enemy:
		return !are_allies;
	case TargetType::Ally:
		return are_allies;
	default:
		return true;
	}
}
