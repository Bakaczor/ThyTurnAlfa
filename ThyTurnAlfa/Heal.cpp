#include "Heal.hpp"
#include "Character.hpp"
#include "Const.hpp"

Heal::Heal(): DefensiveMovement(Const::Heal::HEAL_MOVEMENT_NAME,
								Const::Heal::HEAL_DEFAULT_COST) {}

bool Heal::isInvokable(const Character& who, const Character& on_whom) const {
	return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp > 0;
}

bool Heal::individualAction(Character& who, Character& on_whom) {
	DefensiveMovement::individualAction(who, on_whom);
	on_whom.currentHp += hpBoost;
	if (on_whom.currentHp > on_whom.getHp()) {
		on_whom.currentHp = on_whom.getHp();
	}
	return true;
}
