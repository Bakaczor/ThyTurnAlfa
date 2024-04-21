#include "BleedingAttack.hpp"
#include "Character.hpp"
#include "Bleeding.hpp"

void BleedingAttack::addEffects(Character& who, Character& on_whom)
{
	Bleeding bleeding_effect = Bleeding(BLEEDING_ATTACK_DEFAULT_EFFECT_DURATION,
		BLEEDING_ATTACK_DEFAULT_DAMAGE_PER_ROUND);
	bleeding_effect.addTo(on_whom.activeEffects);
}
