#include "Revive.hpp"

bool Revive::isInvokable(Character& who, Character& on_whom) {
	return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp == 0;
}

bool Revive::individualAction(Character& who, Character& on_whom) {
	on_whom.currentHp = on_whom.hp;
	return true;
}
