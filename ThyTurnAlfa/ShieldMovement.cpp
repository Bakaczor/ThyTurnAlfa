#include "ShieldMovement.hpp"
#include "Shield.hpp"
#include "Character.hpp"

ShieldMovement::ShieldMovement(): DefensiveMovement(Const::ShieldMovement::SHIELD_MOVEMENT_NAME,
													Const::ShieldMovement::SHIELD_MOVEMENT_DEFAULT_COST) {}

bool ShieldMovement::isInvokable(const Character& who, const Character& on_whom) const {
	return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp > 0;
}

void ShieldMovement::addEffects(Character& on_whom) {
	Shield::addTo(on_whom);
}