#include "BleedingAttack.hpp"

void BleedingAttack::addEffects(Character& who, Character& on_whom) {
	Bleeding::addTo(on_whom,
					Const::BleedingAttack::BLEEDING_ATTACK_DEFAULT_EFFECT_DURATION,
					Const::BleedingAttack::BLEEDING_ATTACK_DEFAULT_DAMAGE_PER_ROUND);
};