#include "BleedingAttack.hpp"

BleedingAttack::BleedingAttack(): Attack(Const::BleedingAttack::BLEEDING_ATTACK_MOVEMENT_NAME,
										 Const::BleedingAttack::BLEEDING_ATTACK_DEFAULT_WEIGHT) {}

void BleedingAttack::addEffects(Character& who, Character& on_whom) {
	Bleeding::addTo(on_whom,
					Const::BleedingAttack::BLEEDING_ATTACK_DEFAULT_EFFECT_DURATION,
					Const::BleedingAttack::BLEEDING_ATTACK_DEFAULT_DAMAGE_PER_ROUND);
};