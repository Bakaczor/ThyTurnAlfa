#include "FireAttack.hpp"
#include "Burning.hpp"
#include "Character.hpp"
#include "Const.hpp"

FireAttack::FireAttack(): MagicAttack(Const::FireAttack::FIRE_ATTACK_MOVEMENT_NAME,
									  Const::FireAttack::FIRE_ATTACK_DEFAULT_COST,
									  Const::FireAttack::FIRE_ATTACK_DEFAULT_WEIGHT) {}

void FireAttack::addEffects(Character& on_whom) {
	Burning::addTo(on_whom);
}