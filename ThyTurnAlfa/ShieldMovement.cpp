#include "ShieldMovement.hpp"
#include "Shield.hpp"

ShieldMovement::ShieldMovement(): DefensiveMovement(Const::ShieldMovement::SHIELD_MOVEMENT_NAME,
													Const::ShieldMovement::SHIELD_MOVEMENT_DEFAULT_COST) {}

bool ShieldMovement::isInvokable(Character& who, Character& on_whom) {
	return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp > 0;
}

void ShieldMovement::addEffects(Character& on_whom) {
	Shield::addTo(on_whom);
}