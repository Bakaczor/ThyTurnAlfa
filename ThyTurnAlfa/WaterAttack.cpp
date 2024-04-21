#include "WaterAttack.hpp"
#include "Character.hpp"
#include "Wet.hpp"

void WaterAttack::addEffects(Character& who, Character& on_whom)
{
	Wet wet_effect = Wet(WATER_ATTACK_DEFAULT_EFFECT_DURATION);
	wet_effect.addTo(on_whom.activeEffects);
}
