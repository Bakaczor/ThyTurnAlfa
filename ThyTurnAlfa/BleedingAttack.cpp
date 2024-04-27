#include "BleedingAttack.hpp"
#include "Bleeding.hpp"

BleedingAttack::BleedingAttack(): Attack(Const::BleedingAttack::BLEEDING_ATTACK_MOVEMENT_NAME,
										 Const::BleedingAttack::BLEEDING_ATTACK_DEFAULT_WEIGHT) {}

void BleedingAttack::addEffects(Character& on_whom) {
	Bleeding::addTo(on_whom);
};