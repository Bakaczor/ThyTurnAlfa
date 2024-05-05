#include "Revive.hpp"
#include "Character.hpp"
#include "Const.hpp"

Revive::Revive(): DefensiveMovement(Const::Revive::REVIVE_MOVENT_NAME, 
									Const::Revive::REVIVE_DEFAULT_COST) {}

bool Revive::isInvokable(const Character& who, const Character& on_whom) const {
	return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp == 0;
}

bool Revive::individualAction(Character& who, Character& on_whom) {
	DefensiveMovement::individualAction(who, on_whom);
	on_whom.currentHp = on_whom.getHp();
	on_whom.isAlive = true;
	return true;
}
