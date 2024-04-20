#include "BleedingAttack.hpp"
#include "Character.hpp"
#include "Bleeding.hpp"

bool BleedingAttack::invoke(Character& who, Character& on_whom)
{
	Bleeding bleeding_effect = Bleeding(BLEEDING_ATTACK_DEFAULT_EFFECT_DURATION,
		BLEEDING_ATTACK_DEFAULT_DAMAGE_PER_ROUND);

	int dmg = computeDMG(who, on_whom);
	on_whom.hp -= dmg;
	bleeding_effect.addTo(on_whom.activeEffects);

	return true;
}
