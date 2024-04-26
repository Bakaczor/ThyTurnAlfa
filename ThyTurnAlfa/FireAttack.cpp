#include "FireAttack.hpp"

FireAttack::FireAttack(): MagicAttack(Const::FireAttack::FIRE_ATTACK_MOVEMENT_NAME,
									  Const::FireAttack::FIRE_ATTACK_DEFAULT_COST,
									  Const::FireAttack::FIRE_ATTACK_DEFAULT_WEIGHT) {}

void FireAttack::addEffects(Character& who, Character& on_whom) {
	Burning::addTo(on_whom,
				   Const::FireAttack::FIRE_ATTACK_DEFAULT_EFFECT_DURATION,
				   Const::FireAttack::FIRE_ATTACK_DEFAULT_DAMAGE_PER_ROUND);
}