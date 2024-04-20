#include "WaterAttack.hpp"
#include "Character.hpp"
#include "Wet.hpp"

bool WaterAttack::invoke(Character& who, Character& on_whom)
{
	if (!isExecutable(who, on_whom)) return false;

	int dmg = computeDMG(who, on_whom);
	on_whom.hp -= dmg;

	Wet wet_effect = Wet(WATER_ATTACK_DEFAULT_EFFECT_DURATION);
	
    wet_effect.addTo(on_whom.activeEffects);
	return true;
}
