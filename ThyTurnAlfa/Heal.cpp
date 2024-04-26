#include "Heal.hpp"

Heal::Heal(): DefensiveMovement(Const::Heal::HEAL_MOVEMENT_NAME,
								Const::Heal::HEAL_DEFAULT_COST) {}

bool Heal::isInvokable(Character& who, Character& on_whom) {
	return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp > 0;
}

bool Heal::individualAction(Character& who, Character& on_whom) {
	who.currentMp -= this->cost;
	on_whom.currentHp += hpBoost;
	if (on_whom.currentHp > on_whom.getHp()) {
		on_whom.currentHp = on_whom.getHp();
	}
	return true;
}
