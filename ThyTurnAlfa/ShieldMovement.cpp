#include "ShieldMovement.hpp"

bool ShieldMovement::isInvokable(Character& who, Character& on_whom) {
	return DefensiveMovement::isInvokable(who, on_whom)&&on_whom.currentHp>0;
}

void ShieldMovement::addEffects(Character& who, Character& on_whom) {
	Shield::addTo(on_whom, Const::ShieldMovement::SHIELD_MOVEMENT_DEFAULT_HP);
}