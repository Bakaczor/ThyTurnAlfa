#include "FireAttack.hpp"
#include "Burning.hpp"

void FireAttack::addEffects(Character& who, Character& on_whom)
{
    Burning burning_effect =
        Burning(FIRE_ATTACK_DEFAULT_EFFECT_DURATION, FIRE_ATTACK_DEFAULT_DAMAGE_PER_ROUND);
    burning_effect.addTo(on_whom.activeEffects);
}
